%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "TS.c"

	int yylex();
	int yyerror(char*);

	int is_int(char*);
	int is_float(char*);
	int is_bool_type(char*);
	int is_numeric_type(char*);

	char* type_of(char*);
	char* format_string(char*, ...);
	char* get_bigger_numeric_type(char*, char*);

	void Afficher_Erreur_Semantique(char*);

	extern FILE* yyin;
	extern int col, nb_ligne;
%}

%union {
	int entier;
	char* str;
	float reel;

}

%token  <str> idf        
%token  <str> mc_int mc_float mc_char mc_bool    
%token  <str> mc_addition mc_moins mc_division mc_multiplication
%token  <str> mc_Sup mc_Inf mc_SupE mc_InfE mc_Egal mc_Diff
%token  <str> mc_if mc_else mc_ligne mc_import mc_numpy mc_as mc_matplotlibpyplot mc_zeros
%token  <str> mc_ones mc_arange mc_linspace mc_randint mc_randn mc_dtype mc_uint8
%token  <str> mc_while mc_for mc_in mc_range mc_DPoint mc_point
%token  <entier>Val_int <reel>Val_float <str>Val_char Val_bool
%token  <str> mc_not mc_and  mc_or
%token  <str> mc_parenthese_open mc_parenthese_close
%token  <str> mc_bracket_open mc_bracket_close
%token  <str> mc_affectation mc_Vergule
%token  <str> DEDENT INDENT

%left mc_addition mc_moins
%left mc_multiplication mc_division 
%left mc_affectation
%left mc_or mc_and mc_not
%left mc_Sup mc_SupE mc_Inf mc_InfE mc_Egal mc_Diff

%type <str> Variable_Declaration Declaration_Liste Liste_Variable_Declaration Assign_Variable
%type <str> FOR_idf Array_Reference
%type <str> Type Variable_Value Variable Expression

%start Main_Program
%%

Main_Program:
                Instruction_List
        ;

Instruction_List:
            Instruction_List Instruction
            |
        ;

Block: 
		  Block_Start Instruction_List Block_End 
	;

Block_Start: INDENT { create_new_scope(); }
	;

Block_End: DEDENT { destroy_most_inner_scope(); }
	;

Instruction: Importation
			| Declaration_Type
        	| IF_Statement
        	| WHILE_Statement
        	| FOR_Statement
        	| Assignment 
        	| Block
    ;
Importation : mc_import mc_numpy mc_as idf
		{
			if(!is_declared($4))
			insert($4, "Bilbiotheque");
		}
		| mc_import mc_matplotlibpyplot mc_as idf
		{
			if(!is_declared($4))
			insert($4, "Bilbiotheque");
		}
	;
	
Declaration_Type: 
        Type Declaration_Liste 
			{
				char *Variable = strtok($2, ",");

				while(Variable != NULL) {
					get(Variable)->type = $1;
			
					Variable = strtok(NULL, ",");
				}
			}
	;

Type: mc_int
    | mc_float
    | mc_char
    | mc_bool
    ;

Declaration_Liste: 
                Variable_Declaration Liste_Variable_Declaration
                    { $$ = format_string("%s,%s", $1, $2); }
            ;

Variable_Declaration:
                idf // Ab
                {
				 insert($1, NULL);

				 $$ = $1; // Variable_Declaration = idf ( "Ab" )
			    }
            | idf mc_bracket_open Val_int mc_bracket_close 
			    {
				
				 insert_array($1, NULL, $3);

				 $$ = $1;
			    }
	;

Liste_Variable_Declaration: 
	          mc_Vergule Declaration_Liste
			    { $$ = $2; }
		    | /* epsilon */  { $$ = ""; }
	;

Assignment: 
		  Assign_Variable mc_affectation Expression 
			{
				Identifier *target_Variable = get($1);
				char *Expression_type = $3;

				if (target_Variable->type == NULL)
					target_Variable->type = Expression_type;

				else if (strcmp(target_Variable->type, Expression_type) != 0)
					Afficher_Erreur_Semantique(
						format_string("Impossible assigner type '%s' pour la Variable '%s' of type %s \n", Expression_type, target_Variable->name, target_Variable->type)
					);
			}
	;
// start modification from here !! // first step tokens change 
Assign_Variable:
		  idf
		  	{
				if(!is_declared($1))
					insert($1, NULL);
				
				$$ = $1;
			}

		| idf mc_bracket_open Val_int mc_bracket_close 
			{
				Identifier *id = get($1);
				int indice = $3;

				if(id == NULL) 
					Afficher_Erreur_Semantique(format_string("Variable '%s' n'est pas declarer \n", $1));
				
				if (!id->is_array)
					Afficher_Erreur_Semantique(format_string("Variable '%s' n'est pas un vecteur (Tableau) \n", id->name));
				
				if (indice >= id->array_size)
					Afficher_Erreur_Semantique(format_string("indice %d out hors tableau '%s' borne \n", indice, id->name));
				
				$$ = $1;
			}
	;

IF_Statement:
		  mc_if mc_parenthese_open Conditions mc_parenthese_close mc_DPoint Block
		| mc_if mc_parenthese_open Conditions mc_parenthese_close mc_DPoint Block mc_else mc_DPoint Block
			
	;

WHILE_Statement:
		  mc_while mc_parenthese_open Conditions mc_parenthese_close mc_DPoint Block
	
	;

Conditions:
		  Expression
		  	{
				if (!is_bool_type($1))
					Afficher_Erreur_Semantique(format_string("La condition doivent être de type booléen mais obtenues d'autre type : '%s' \n", $1));
			}
	;

FOR_Statement:
		  For_Array mc_DPoint FOR_Block
		| FOR_InRange_Form mc_DPoint FOR_Block
	;


For_Array:
		  FOR_KeyWord FOR_idf mc_in Array_Reference
			{
				Identifier *array = get($4);
				Identifier *iterator = get($2);

				iterator->type = array->type;
			}
	;

FOR_InRange_Form: 
		  FOR_KeyWord FOR_idf mc_in Range_State
			{
				Identifier *iterator = get($2);
				iterator->type = "int";
			}
	;

FOR_KeyWord: mc_for { create_new_scope(); }
	;

FOR_Block: INDENT Instruction_List DEDENT { destroy_most_inner_scope(); }
	;

FOR_idf: 
		  idf
			{
				insert($1, NULL);
				$$ = $1;
			}
	;


Array_Reference: idf {		
				        Identifier *id = get($1);

				        if (id == NULL) Afficher_Erreur_Semantique(format_string("Variable '%s' n'est pas declarer  \n", $1));

				        if (!id->is_array) Afficher_Erreur_Semantique(format_string("Variable '%s' n'existe pas dans tableau  \n", $1));
				
				        $$ = $1;
                     }
	;


Range_State:
		  mc_range mc_parenthese_open Val_int  mc_parenthese_close
			{
				if ($3 <= 0)
					Afficher_Erreur_Semantique(format_string("Borne sup '%d' doit etre superieur a zero '%d'  \n", $3));
			}
		|
		  mc_range mc_parenthese_open Val_int mc_Vergule Val_int mc_parenthese_close
			{
				if ($3 >= $5)
					Afficher_Erreur_Semantique(format_string("Borne inf '%d' obliger etre moins que la borne sup '%d'  \n", $3, $5));
			}
		| mc_range mc_parenthese_open Val_int mc_Vergule Val_int mc_Vergule Val_int mc_parenthese_close
			{
				if ($3 >= $5)
					Afficher_Erreur_Semantique(format_string("Borne inf '%d' obliger etre moins que la borne sup '%d'  \n", $3, $5));
				
				if ($7 <= 0)
					Afficher_Erreur_Semantique(format_string("Le pas '%d' doit etre superieur a zero  \n", $7));
			}
	;

Expression:
		  Expression mc_multiplication Expression
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateurr '*' attendre avoir operateur type numerique (int, float) mais resultat : '%s * %s' \n", $1, $3)
					);
				
				$$ = get_bigger_numeric_type($1, $3);
			}

		| Expression mc_division Expression
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '/' attendre avoir operateur type numerique (int, float) mais resultat : %s / %s \n", $1, $3)
					);
				
				$$ = get_bigger_numeric_type($1, $3);
			}
		
		| Expression mc_addition Expression
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '+' attendre avoir operateur type numerique (int, float) mais resultat : %s + %s \n", $1, $3)
					);
				
				$$ = get_bigger_numeric_type($1, $3);
			}

		| Expression mc_moins Expression 
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '-' attendre avoir operateur type numerique (int, float) mais resultat : %s - %s \n", $1, $3)
					);
				
				$$ = get_bigger_numeric_type($1, $3);
			}

		| Expression mc_and Expression
			{
				if (!is_bool_type($1) || !is_bool_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur 'and' attendre avoir operateur type boolean (true, false) mais resultat : %s and %s \n", $1, $3)
					);

				$$ = "bool";
			}
		| Expression mc_or Expression 
			{
				if (!is_bool_type($1) || !is_bool_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur 'or' attendre avoir operateur type boolean (true, false) mais resultat : %s or %s \n", $1, $3)
					);

				$$ = "bool";
			}

		| mc_not Expression 
			{
				if (!is_bool_type($2))
					Afficher_Erreur_Semantique(
						format_string("Operateur 'not' attendre avoir operateur type boolean (true, false) mais resultat : not %s \n", $2)
					);

				$$ = "bool";
			}

		| Expression mc_SupE Expression 
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '>=' attendre avoir operateur type boolean (true, false) mais resultat : %s >= %s \n", $1, $3)
					);

				$$ = "bool";
			}

		| Expression mc_InfE Expression 
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '<=' attendre avoir operateur type boolean (true, false) mais resultat : %s <= %s \n", $1, $3)
					);

				$$ = "bool";
			}

		| Expression mc_Egal Expression
			{
				if (strcmp($1, $3) != 0)
					if (!is_numeric_type($1) || !is_numeric_type($3))
						Afficher_Erreur_Semantique(
							format_string("Operateur '==' attendre avoir operateur de meme type (exp: int == int) mais resultat : %s == %s \n", $1, $3)
						);

				$$ = "bool";
			}

		| Expression mc_Diff Expression
			{
				if (strcmp($1, $3) != 0)
					if (!is_numeric_type($1) || !is_numeric_type($3))
						Afficher_Erreur_Semantique(
							format_string("Operateur '!=' attendre avoir operateur de meme type (exp: int != int) mais resultat : %s != %s \n", $1, $3)
						);

				$$ = "bool";
			}

		| Expression mc_Sup Expression
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '>' attendre avoir operateur type numerique (int, float) mais resultat : %s > %s \n", $1, $3)
					);

				$$ = "bool";
			}

		| Expression mc_Inf Expression 
			{
				if (!is_numeric_type($1) || !is_numeric_type($3))
					Afficher_Erreur_Semantique(
						format_string("Operateur '<' attendre avoir operateur type numerique (int, float) mais resultat : %s < %s \n", $1, $3)
					);

				$$ = "bool";
			}

		| Variable_Value 
			{ $$ = type_of($1); }

		| idf mc_point mc_zeros mc_parenthese_open mc_bracket_open Val_int mc_Vergule Val_int mc_bracket_close DTYPE mc_parenthese_close 
			{ $$ = "array"; }
	;
DTYPE: mc_Vergule mc_dtype mc_affectation idf mc_point mc_uint8;
    	|

Variable_Value:
		  Variable
		  	{ $$ = $1; }

		| Val_int
			{ $$ = format_string("%d", $1); }
		
		| Val_float 
			{ $$ = format_string("%f", $1); }
		| mc_parenthese_open mc_moins Val_float mc_parenthese_close 
			{ $$ = format_string("%s%f", $2, $3); }

		| Val_bool 
			{ $$ = $1; }

		| Val_char
			{ $$ = format_string("'%c'", $1); }

		| mc_parenthese_open Expression mc_parenthese_close 
			{ $$ = $2; }
	;

Variable: 
		  idf
			{
				Identifier *id = get($1);
				
				if (id == NULL) Afficher_Erreur_Semantique(format_string("Variable '%s' est non declarer ! \n", $1));
				
				if (id->is_array) Afficher_Erreur_Semantique(format_string("Variable '%s' c'est un tableau, tu peut seulement utilise la referance ! (nom de variable) \n", $1));

				$$ = $1;
			} 

		| idf mc_bracket_open Val_int mc_bracket_close // 
			{
				Identifier *id = get($1);
				int indice = $3;

				if (id == NULL) 
					Afficher_Erreur_Semantique(format_string("Tableau %s non declarer ! \n", $1));
				
				if (!id->is_array)
					Afficher_Erreur_Semantique(format_string("Variable '%s' c'est pas un tableau \n", $1));
				
				if (indice >= id->array_size)
					Afficher_Erreur_Semantique(format_string("indice %d hors tableau %s borne ! \n", indice, id->name));
				
				$$ = $1;
			}
	;
%%

int yyerror(char* msg) 
{
	printf("Erruer Syntaxique: %s, Ligne : %d , colonne : %d, entite lexicale (%s) \n", msg, nb_ligne, col, yylval.str);

	return 1;
}

void Afficher_Erreur_Semantique(char* message)
{
	printf("Erruer Semantique: %s\nLigne => %d\ncolumn => %d \n", message, nb_ligne, col);

	exit(1);
}


char *format_string(char* format, ...) 
{
	va_list args;
	va_start(args, format);

	char* str = (char*) malloc(100);
	vsprintf(str, format, args);

	va_end(args);

	return str;
}

char *type_of(char* str)
{
	if (strcmp(str, "true") == 0 || strcmp(str, "false") == 0)
		return "bool";

	if (str[0] == '\'' && str[2] == '\'')
		return "char";

	if (str[0] == '-' && is_int(str) || is_int(str))
		return "int";

	if (str[0] == '-' && is_float(str) || is_float(str))
		return "float";

	return get(str)->type;
}

int is_numeric_type(char* str)
{
	return strcmp(str, "int") == 0 || strcmp(str, "float") == 0;
}

int is_bool_type(char* str)
{
	return strcmp(str, "bool") == 0;
}

int is_float(char *str) 
{
    char *endptr;

    strtod(str, &endptr);

    if (endptr == str || *endptr != '\0')
        return 0;
    
    return 1;
}

int is_int(char *str)
{
	char *endptr;

    strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
        return 0;
    
    return 1;
}

char *get_bigger_numeric_type(char* type1, char* type2)
{
	if (strcmp(type1, "float") == 0 || strcmp(type2, "float") == 0)
		return "float";

	return "int";
}

int main (int argc, char** argv) 
{ 	
	yyin = fopen("in.minipy", "r");

	create_new_scope();
    display();
	yyparse();

	display();
	fclose (yyin);

	return 0;
}
