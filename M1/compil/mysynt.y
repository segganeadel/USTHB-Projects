%token idf cst aff pvg


%%
S: idf aff cst pvg {printf("syntaxe correcte");
    YYACCEPT;}
;


%%
int yyerror(char *msg){
    printf("%s error syntaxique");
    return 1; 
}

main(){
    yyparse();
}

yywrap()
{}