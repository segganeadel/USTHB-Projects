%option yylineno
%{

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "myTS.h"
	#include "syntaxique.tab.h"
	extern YYSTYPE yylval;
	extern yylineo;
	extern col;
%}

git config --global user.email "segganeadel@gmail.com"
ltr [a-zA-Z]
ltrmin [a-z]
ltrmaj [A-Z]
chfr [0-9]
idf {ltrmaj}({ltrmin}|{chfr}|_)*
const_int ([1-9][0-9]*)|0
const_float ([1-9][0-9]*\.[0-9]+)|(0\.[0-9]+)
const_int_s \(([+-]?([1-9][0-9]*|0))\)
const_float_s \(([+-]?([1-9][0-9]*\.[0-9]+)|(0\.[0-9]+))\)
const_ch \'{ltr}\'
const_str \"[^\"]+\"
comm \#[^#]+\!
saut [\n]

%%


{comm}
"IDENTIFICATION DIVISION" {rechercher (yytext,"mc_idendiv"," ",0, 1); col += strlen(yytext);return mc_idendiv;}
"PROGRAM-ID" {rechercher (yytext,"mc_progid"," ",0, 1); col += strlen(yytext);return mc_progid;}
"DATA DIVISION" {rechercher (yytext,"mc_datadiv"," ",0, 1); col += strlen(yytext); return mc_datadiv; return mc_datadiv;}
"WORKING-STORAGE SECTION" {rechercher (yytext,"mc_stodiv"," ",0, 1); col += strlen(yytext); return mc_stodiv;}
"PROCEDURE DIVISION" {rechercher (yytext,"mc_prodiv"," ",0, 1); col += strlen(yytext); return mc_prodiv;}
"STOP RUN" {rechercher (yytext,"mc_stop"," ",0, 1); col += strlen(yytext); return mc_stop;}
TYPE {rechercher (yytext,"mc_type"," ",0, 1); col += strlen(yytext); return mc_type;}
COMPUTE {rechercher (yytext,"mc_compute"," ",0, 1); col += strlen(yytext); return mc_compute;}
ACCEPT {rechercher (yytext,"mc_accept"," ",0, 1); col += strlen(yytext); return mc_accept;}
DISPLAY {rechercher (yytext,"mc_display"," ",0, 1); col += strlen(yytext); return mc_display;}
READ {rechercher (yytext,"mc_read"," ",0, 1); col += strlen(yytext);return mc_read;}
LINE {rechercher (yytext,"mc_line"," ",0, 1); col += strlen(yytext);return mc_line;}
SIZE {rechercher (yytext,"mc_size"," ",0, 1); col += strlen(yytext);return mc_size;}
IF {rechercher (yytext,"mc_if"," ",0, 1); col += strlen(yytext);return mc_if;}
ELSE {rechercher (yytext,"mc_else"," ",0, 1); col += strlen(yytext);return mc_else;}
MOVE {rechercher (yytext,"mc_move"," ",0, 1); col += strlen(yytext);return mc_move;}
TO {rechercher (yytext,"mc_to"," ",0, 1); col += strlen(yytext);return mc_to;}
END {rechercher (yytext,"mc_end"," ",0, 1); col += strlen(yytext);return mc_end;}
INTEGER {rechercher (yytext,"mc_int"," ",0, 1); col += strlen(yytext);yylval.str=strdup(yytext);return mc_int;}
FLOAT {rechercher (yytext,"mc_float"," ",0, 1); col += strlen(yytext);yylval.str=strdup(yytext);return mc_float;}
CHAR {rechercher (yytext,"mc_char"," ",0, 1); col += strlen(yytext);yylval.str=strdup(yytext);return mc_char;}
STRING {rechercher (yytext,"mc_string"," ",0, 1); col += strlen(yytext);yylval.str=strdup(yytext);return mc_str;}
CONST {rechercher (yytext,"mc_const"," ",0, 1); col += strlen(yytext);return mc_const;}
NOT {rechercher (yytext,"mc_not"," ",0, 1); col += strlen(yytext);return mc_not;}
OR {rechercher (yytext,"mc_or"," ",0, 1); col += strlen(yytext);return mc_or;}
AND {rechercher (yytext,"mc_and"," ",0, 1); col += strlen(yytext);return mc_and;}
G {rechercher (yytext,"mc_sup"," ",0, 1); col += strlen(yytext);return mc_sup;}
GE {rechercher (yytext,"mc_supega"," ",0, 1); col += strlen(yytext);return mc_supega;}
EQ {rechercher (yytext,"mc_ega"," ",0, 1); col += strlen(yytext);return mc_ega;}
DI {rechercher (yytext,"mc_diff"," ",0, 1); col += strlen(yytext);return mc_diff;}
LE {rechercher (yytext,"mc_infega"," ",0, 1); col += strlen(yytext);return mc_infega;}
L {rechercher (yytext,"mc_inf"," ",0, 1); col += strlen(yytext);return mc_inf;}
"+" {rechercher (yytext,"sep_plus"," ",0, 2); col += strlen(yytext);yylval.car=yytext[1];return sep_plus;}
"-" {rechercher (yytext,"sep_moins"," ",0, 2); col += strlen(yytext);yylval.car=yytext[1];return sep_moins;}
"*" {rechercher (yytext,"sep_etoile"," ",0, 2); col += strlen(yytext);yylval.car=yytext[1];return sep_etoile;}
"/" {rechercher (yytext,"sep_slash"," ",0, 2); col += strlen(yytext);yylval.car=yytext[1];return sep_slash;}
"=" {rechercher (yytext,"sep_ega"," ",0, 2); col += strlen(yytext);return sep_ega;}
"(" {rechercher (yytext,"sep_parouv"," ",0, 2); col += strlen(yytext);return sep_parouv;}
")" {rechercher (yytext,"sep_parferm"," ",0, 2); col += strlen(yytext);return sep_parferm;}
"." {rechercher (yytext,"sep_point"," ",0, 2); col += strlen(yytext);return sep_point;}
":" {rechercher (yytext,"sep_dpoint"," ",0, 2); col += strlen(yytext);return sep_dpoint;}
";" {rechercher (yytext,"sep_pvg"," ",0, 2); col += strlen(yytext);return sep_pvg;}
"@" {rechercher (yytext,"sep_arob"," ",0, 2); col += strlen(yytext);return sep_arob;}
"$" {rechercher (yytext,"sep_dollar"," ",0, 2); col += strlen(yytext);return sep_dollar;}
"%" {rechercher (yytext,"sep_pourc"," ",0, 2); col += strlen(yytext);return sep_pourc;}
"#" {rechercher (yytext,"sep_dieze"," ",0, 2); col += strlen(yytext);return sep_dieze;}
"!" {rechercher (yytext,"sep_exclam"," ",0, 2); col += strlen(yytext);return sep_exclam;}
"&" {rechercher (yytext,"sep_and"," ",0, 2); col += strlen(yytext);return sep_and;}
"," {rechercher (yytext,"sep_virg"," ",0, 2); col += strlen(yytext);return sep_virg;}
"'" {rechercher (yytext,"sep_gill"," ",0, 2); col += strlen(yytext);return sep_gill;}
"{" {rechercher (yytext,"sep_acco"," ",0, 2); col= col+ strlen (yytext);return sep_acco;}
"}" {rechercher (yytext,"sep_accf"," ",0, 2); col= col+ strlen (yytext);return sep_accf;}
"[" {rechercher (yytext,"sep_crov"," ",0, 2); col= col+ strlen (yytext);return sep_crov;}
"]" {rechercher (yytext,"sep_crof"," ",0, 2); col= col+ strlen (yytext);return sep_crof;}
"|" {rechercher (yytext,"sep_barre"," ",0, 2); col= col+ strlen (yytext);return sep_barre;}
" " {col += strlen(yytext);}
\t {col += strlen(yytext);}

{saut} {col=1;yylineo++;}

{const_int} {rechercher (yytext,"const_int","INTEGER",atoi(yytext), 0); col += strlen(yytext); 
			yylval.entier=atoi(yytext); 
			return const_int;}
{const_int_s} { 
				rechercher (yytext,"const_int_s","INTEGER",atoi(yytext), 0);
				col += strlen(yytext);
				yylval.entier=atoi(yytext);
				return const_int_s;}

{const_float} {rechercher (yytext,"const_float","FLOAT",atof(yytext), 0); col += strlen(yytext);yylval.reel=atof(yytext); return const_float;}
{const_float_s} {
				int i;
				char result[20];
				for(i=0; i<strlen(yytext); i++)
				{
					result[i]=yytext[i+1];
				}
				result[strlen(result)]='\0';
				rechercher (result,"const_float_s","FLOAT",atof(yytext), 0); 
				col += strlen(yytext);
				yylval.reel=atof(result);
				return const_float_s;}

{const_ch} {rechercher (yytext,"const_ch","CHAR",-32769, 0); col += strlen(yytext);yylval.car=yytext[1];return const_ch;}
{const_str} {rechercher (yytext,"const_str","STRING",-32769, 0); col += strlen(yytext);yylval.str=strdup(yytext);return const_str;}


{idf}        { 
               rechercher (yytext,"IDF "," ",-32769, 0); col= col+ strlen (yytext); 
               if (yyleng<10) { yylval.str=strdup(yytext);return idf;}
                else printf ("Erreur lexicale: IDF trop long \"%s\" a la ligne %d et a la colonne %d \n", yytext, yylineno, col);
			 }		 
. printf("Erreur lexicale a la ligne %d col %d \n",yylineno,col);

%%
