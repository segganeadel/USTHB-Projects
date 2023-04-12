%{
  #define YY_USER_INIT { BEGIN(indent_mode);}

  #include "synt.tab.c"
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  extern YYSTYPE yylval;
  int nb_ligne = 1;
  int col = 1;
  int current_line_indent = 0;   /* indentation of the current line */
  int indent_level = 0;          /* indentation level passed to the parser */
%}

%x indent_mode 
lettreM [A-Z]
lettre [a-zA-Z]
chiffre [0-9]
indentation "    "
commentaire ("#"(.)*)
IDF {lettreM}({lettre}|{chiffre})*
VAL_CHAR      \'[^']\'   
VAL_INT  ({chiffre}+|"\("[+-]{chiffre}+"\)")
VAL_FLOAT	{chiffre}+"."{chiffre}+
VAL_BOOL ("true"|"false")
Val_Taille ("["{chiffre}+"]")
Borne {chiffre}+



%%

<indent_mode>{indentation} { current_line_indent++; col += yyleng; }
<indent_mode>"\n" { nb_ligne++; col = 1; current_line_indent = 0; }
<indent_mode><<EOF>> {
                        if (current_line_indent < indent_level) {
                           //printf("send dedent from eof \n\n");
                            indent_level--;
                            return DEDENT;
                        }
                        BEGIN(INITIAL);
                    }
<indent_mode>. {
                    //printf("Line : %d, Indentation end, current indentation level: %d, previous indentation level: %d \n", line_number, current_line_indent, indent_level);
                    unput(*yytext);  //      first line 
                    // seconde line 
                    if (current_line_indent > indent_level) {
                        indent_level++;
                        return INDENT;
                    }
                    if (current_line_indent < indent_level) {
                        indent_level--;
                        return DEDENT;
                    }
                    BEGIN(INITIAL);
                }

" "                { col += yyleng;}
int       {printf("mot cle 'integer' reconnue \n"); yylval.str = strdup(yytext); col = col+strlen(yytext); return mc_int;}
float     {printf("mot cle 'float' reconnue \n"); yylval.str = strdup(yytext); col = col+strlen(yytext); return mc_float;}
char      {printf("mot cle 'char' reconnue \n");  yylval.str = strdup(yytext); col = col+strlen(yytext); return mc_char;}
bool	     {printf("mot cle 'bool' reconnue \n");  yylval.str = strdup(yytext);col = col+strlen(yytext); return mc_bool;}
"+"       {printf("addition '+' reconnue : %s \n",yytext);  yylval.str = strdup(yytext);col = col + strlen(yytext); return mc_addition;}
"-"       {printf("Subtraction '-' reconnue : %s \n",yytext); yylval.str = strdup(yytext);col = col + strlen(yytext); return mc_moins;}
"/"       {printf("division '/' reconnue : %s \n",yytext); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_division;}
"*"       {printf("multi '*' reconnue : %s \n",yytext); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_multiplication;}
"and"     {printf("mot cle 'and' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_and;}
"or"      {printf("mot cle 'or' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_or;}
"not"     {printf("mot cle 'not' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_not;}
">"       {printf("mot cle '>' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_Sup;} 
"<"       {printf("mot cle '<' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_Inf;}
">="      {printf("mot cle '>=' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_SupE;} 
"<="      {printf("mot cle '<=' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_InfE;}
"=="      {printf("mot cle '==' reconnu \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_Egal;}
"!="      {printf("mot cle '!=' \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_Diff;}
")"       {printf("parenthese ')' reconnue \n"); yylval.str = strdup(yytext); col = col + strlen(yytext); return mc_parenthese_close;}
"("       {printf("parenthese '(' reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_parenthese_open;}
"["       {printf("parenthese '[' reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_bracket_open;}
"]"       {printf("parenthese ']' reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_bracket_close;}
"if"        {printf("mot cle 'if' reconnue \n");  col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_if;}
"else"      {printf("mot cle 'else' reconnue \n");  col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_else;}
"while"     {printf("mot cle 'while'  reconnue \n");  col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_while;}
"for"       {printf("mot cle 'for'  reconnue \n"); col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_for;}
"in"        {printf("mot cle 'in' reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_in;}
"range"     {printf("mot cle 'range'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_range;}
"import"     {printf("mot cle 'import'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_import;}
"numpy"     {printf("mot cle 'numpy'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_numpy;}
"matplotlib.pyplot"     {printf("mot cle 'matplotlib.pyplot'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_matplotlibpyplot;}
"as"     {printf("mot cle 'as'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_as;}
"zeros"     {printf("mot cle 'zeros'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_zeros;}
"dtype"     {printf("mot cle 'dtype'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_dtype;}
"uint8"     {printf("mot cle 'uint8'  reconnue \n");col = col + strlen(yytext); yylval.str = strdup(yytext); return mc_uint8;}
"="         {printf("affectation '=' reconnue \n"); yylval.str = strdup(yytext); col = col+strlen(yytext); return mc_affectation;}
":"         {printf("deuxPoint ':' reconnue \n");col = col+strlen(yytext); yylval.str = strdup(yytext); return mc_DPoint;}
","         {printf("vergule reconnue \n");col = col+strlen(yytext); yylval.str = strdup(yytext); return mc_Vergule;}
"."         {printf("point reconnue \n");col = col+strlen(yytext); yylval.str = strdup(yytext); return mc_point;}
{commentaire}   {printf("commentaire reconnu : %s \n",yytext);}
{IDF}        {if(strlen(yytext)<= 8) {printf("IDF reconnue : %s \n",yytext); yylval.str = strdup(yytext); col = col + strlen(yytext); return idf;}
                          else {printf("erreur lexicale : IDF trop long : %s \n",yytext);}}
{VAL_INT}  {if(atoi(yytext) > -32768 || atoi(yytext) < 32768){
	          printf("Entite Lexical reconnue %s \n" , yytext );
             col = col + strlen(yytext); yylval.entier=atoi(yytext); return Val_int;
	        }
	        else{
              printf("integer invalide ligne: %d,colonne: %d",nb_ligne,col);
                }} 
{VAL_FLOAT} {printf("REEL reconnue : %s \n",yytext); yylval.reel = atoi(yytext); col = col+strlen(yytext); return Val_float;}
{VAL_CHAR}  {printf("CHAR reconnue : %s \n",yytext); yylval.str = strdup(yytext); col = col+strlen(yytext); return Val_char;}
{VAL_BOOL}  {printf("BOOLEAN reconnue : %s \n",yytext); yylval.str = strdup(yytext); col = col+strlen(yytext); return Val_bool;}

\n          {nb_ligne++; col = 1; current_line_indent = 0; BEGIN(indent_mode);}

<<EOF>> {
            if (indent_level == 0)
                return 0;

            indent_level--;
            return DEDENT;
        }

. {printf ("Erreur lexicale : Entite lexicale non reconnue '%s' a la ligne : %d , et la colonne : %d\n",yytext, nb_ligne, col);}


%%