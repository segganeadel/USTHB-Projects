%{


        int yylineo = 1;
        int col = 1 ;
        int yylex();
	char* sauvtype[25];
        extern yytext;
        // extern yyin;

%}

%union{
  float reel;
  char* str;
  int entier;
  char car;
}

%token mc_idendiv sep_dgill 
%token mc_progid mc_datadiv mc_stodiv mc_prodiv mc_stop 
%token mc_type mc_compute mc_accept mc_display mc_read mc_line mc_size 
%token mc_if mc_else mc_move mc_to mc_end <str>mc_int <str>mc_float <str>mc_char <str>mc_str 
%token mc_const mc_not mc_or mc_and mc_sup mc_supega mc_ega mc_diff mc_infega mc_inf 
%token <car>sep_plus <car>sep_moins <car>sep_etoile <car>sep_slash sep_ega sep_parouv sep_parferm 
%token sep_point sep_dpoint sep_pvg sep_arob sep_dollar sep_pourc sep_dieze sep_exclam 
%token sep_and sep_virg sep_bslash sep_gill sep_esp sep_tab sep_acco sep_accf sep_crov sep_crof sep_barre

%token <str> idf const_str
%token <entier> const_int const_int_s
%token <reel> const_float const_float_s
%token <car> const_ch

%left mc_or mc_and mc_sup mc_supega mc_ega mc_diff mc_infega mc_inf sep_plus sep_moins sep_etoile sep_slash  

%type <entier> OPERANDES
%type <str> TYPE LISTE_IDF LINE
%type <car> OPA

%start S

%%

S: mc_idendiv sep_point mc_progid sep_point idf sep_point mc_datadiv sep_point mc_stodiv sep_point DECLARATION mc_prodiv sep_point INSTRUCTION mc_stop sep_point {printf("Programme syntaxiquement correcte \n"); YYACCEPT;}
;


DECLARATION: DEC DECLARATION
            |DEC_TAB DECLARATION
            |DEC_CST DECLARATION
            |
;


DEC :  LISTE_IDF TYPE sep_point {if (doubledecl($1)) {printf("Erreur double declaration \"%s\" : Ligne %d Col %d\n",$1,yylineo,col);YYERROR;}
                                maj_type_idf($2);
}
;


LISTE_IDF : idf sep_barre LISTE_IDF {sauver_idf($1);}
            |idf {sauver_idf($1);}
;

TYPE: mc_int 
    | mc_float
    | mc_char
    | mc_str
;

DEC_CST: mc_const idf sep_ega CONSTANTE sep_point {modifier_type($2,"CONST");}
        |mc_const idf TYPE sep_point {modifier_type($2,"CONST");}
;

DEC_TAB : idf mc_line const_int sep_virg mc_size const_int TYPE sep_point 
;

CONSTANTE : CONSTANTE_NUM
          | CONSTANTE_LIT
;

CONSTANTE_NUM : const_int
              | const_float
              | const_int_s
              | const_float_s
;

CONSTANTE_LIT : const_ch
              | const_str
;




INSTRUCTION:  AFFEC INSTRUCTION
            | ACCEPT INSTRUCTION 
            | DISP INSTRUCTION
            | BOUCLE INSTRUCTION
            | OPERATION_AR INSTRUCTION
            | CONDITION INSTRUCTION
            | CALCUL INSTRUCTION
            |
;

AFFEC : idf sep_ega CONSTANTE_LIT sep_point
;

ACCEPT: mc_accept sep_parouv const_str sep_dpoint sep_arob idf sep_parferm sep_point {
          switch ($3[1]){
    case '$':
      if (!(strcmp(type_idf($6),"INTEGER")==0))   {printf("Mauvais formatage \"%c\" : Ligne %d Col %d\n",$3[1],yylineo,col);YYERROR;}
      break;
    case '#':
      if (!(strcmp(type_idf($6),"STRING")==0) )   { printf("Mauvais formatage \"%c\" : Ligne %d Col %d\n",$3[1],yylineo,col);YYERROR;}
      break;
  case '%':
      if (!(strcmp(type_idf($6),"FLOAT")==0) )    {printf("Mauvais formatage \"%c\" : Ligne %d Col %d\n",$3[1],yylineo,col);YYERROR;}
      break;
   case '&':
      if (!(strcmp(type_idf($6),"CHAR")==0) )    {printf("Mauvais formatage \"%c\" : Ligne %d Col %d\n",yylineo,col);YYERROR;}
      break;
    default:
      yyerror();YYERROR;}
     

}
;

DISP : mc_display sep_parouv const_str sep_dpoint LISTE_IDF sep_parferm sep_point
;

BOUCLE: mc_move idf mc_to idf INSTRUCTION mc_end sep_point
      | mc_move idf mc_to const_int INSTRUCTION mc_end sep_point
      | mc_move const_int mc_to const_int INSTRUCTION mc_end sep_point
;

CONDITION : mc_if OPERATION_LC sep_dpoint INSTRUCTION mc_end sep_point
          | mc_if OPERATION_LC sep_dpoint INSTRUCTION mc_else sep_dpoint INSTRUCTION mc_end sep_point
;

CALCUL : idf sep_ega LINE sep_point 
;


EXP : sep_parouv LINE sep_parferm

;

LINE :   EXP
        |OPERANDES
        |EXP OPA LINE
        |OPERANDES OPA LINE 
;

OPERANDES : idf {
        if (nondeclare ($1)) {printf("Erreur idf \"%s\" non declare : Ligne %d Col %d\n",$1,yylineo,col);YYERROR;}
        else{
        if (nonintial ($1)) {printf("Erreur idf \"%s\" non intialise : Ligne %d Col %d\n",$1,yylineo,col);YYERROR;}}
        }
          | CONSTANTE_NUM
; 


OPERATION_AR :  EXP OPA EXP
;

OPERATION_LC : OPERATION_C
             | OPERATION_L
;

OPERATION_C : sep_parouv LINE sep_point OPC sep_point LINE sep_parferm
;

OPERATION_L : sep_parouv OPER sep_parferm

OPER : OPERATION_C
        | OPERATION_C sep_point OPL sep_point OPER
        | sep_parouv mc_not OPERATION_C sep_point OPL sep_point OPER sep_parferm
        | sep_parouv mc_not OPERATION_C sep_parferm
        |
;

OPA : sep_plus
    | sep_moins
    | sep_etoile
    | sep_slash
;

OPL : mc_or
    | mc_and
;

OPC : mc_sup
    | mc_supega
    | mc_inf
    | mc_infega
    | mc_ega
    | mc_diff
;



%%
main () 
{
        printf("\n\n\n");
        initialisation();
        yyparse();
        afficher();
        return 0;
}


yywrap()
{}

yyerror(char* msg){
        if (strcmp(msg,"")) printf("Erreur syntaxique \"%s\" : Ligne %d Col %d\n",yytext,yylineo,col);
        else printf("%s",msg);
}



