#include <stdio.h>
#include <stdlib.h>

extern int yylineo;
extern int col;

typedef struct elt {
    char name[30];
    char code[30];
    char type[30];
    float val;
    struct elt* suiv;
} elt;

elt* list_idf_cst;
elt* list_mc;
elt* list_sep;
elt* ptr_idf;
elt* ptr_mc;
elt* ptr_sep;
elt* gen;

char sauve[20][20];
int pos=0;

void initialisation()
{

list_idf_cst = (elt*)malloc(sizeof(elt));
list_mc = (elt*)malloc(sizeof(elt));
list_sep = (elt*)malloc(sizeof(elt));

list_idf_cst->suiv=NULL;
list_mc->suiv=NULL;
list_sep->suiv=NULL;

ptr_idf = list_idf_cst;
ptr_mc = list_mc;
ptr_sep = list_sep;

}







void inserer (char entite[], char code[],char type[],float val, int y)
{
  switch (y)
 { 
   case 0:
    gen=list_idf_cst;
    while (gen->suiv != NULL) {gen = gen->suiv;}
    gen->suiv = (elt*)malloc(sizeof(elt));
    gen=gen->suiv;
    strcpy(gen->name,entite);
    strcpy(gen->code,code);
    strcpy(gen->type,type);
    gen->val=val;
    gen->suiv=NULL;
    break;

   case 1:
    gen=list_mc;
    while (gen->suiv != NULL) {gen = gen->suiv;}
    gen->suiv = (elt*)malloc(sizeof(elt));
    gen=gen->suiv;
    strcpy(gen->name,entite);
    strcpy(gen->code,code);
    strcpy(gen->type,type);
    gen->val=val;
    gen->suiv=NULL;
    break;

   case 2:
    gen=list_sep;
    while (gen->suiv != NULL) {gen = gen->suiv;}
    gen->suiv = (elt*)malloc(sizeof(elt));
    gen=gen->suiv;
    strcpy(gen->name,entite);
    strcpy(gen->code,code);
    strcpy(gen->type,type);
    gen->val=val;
    gen->suiv=NULL;
    break;
 }

}


void rechercher (char entite[], char code[],char type[],float val,int y)	
{

switch(y) 
  {
   case 0:
    gen = list_idf_cst;
    if (gen->suiv != NULL)
    {
      while ((gen != NULL) && (strcmp(entite, gen->name) != 0))
      {
        gen = gen->suiv;
      }

      if (gen == NULL) inserer(entite, code, type, val, 0);
    }
    else inserer(entite, code, type, val, 0);
    break;


   case 1:
       
        gen = list_mc;
        gen = gen->suiv;
        if (gen != NULL)
        {        
          while ((gen != NULL) && (strcmp(entite,gen->name)!=0))
          {
            gen = gen->suiv;
          }

          if (gen == NULL) inserer(entite, code, type, val,1);
        }
        else inserer(entite,code,type,val,1);
        break; 
        

   case 2:
        gen = list_sep;
        gen = gen->suiv;
        if (gen != NULL)
        {        
          while ((gen != NULL) && (strcmp(entite,gen->name)!=0))
          {
          gen = gen->suiv;
          }

          if (gen == NULL) inserer(entite, code, type, val,2);
        }
        else inserer(entite,code,type,val,2);
        break;
    }
}

void afficher()
{
  printf("\n\n\n");
  printf("/***************Table des symboles IDF*************/\n");
  printf("\t____________________________________________________________________\n");
  printf("\t|         NomEntite        |  Code_Entite | Type_Entite | Val_Entite\n");
  printf("\t____________________________________________________________________\n");

  gen = list_idf_cst;
  gen = gen->suiv;
  while (gen != NULL)
  {	
    printf("\t|%25s |%13s | %11s | %13f\n",gen->name,gen->code,gen->type,gen->val);
    gen = gen->suiv;
  }


  printf("\n/***************Table des symboles mots cles*************/\n");
  printf("\t__________________________________________\n");
  printf("\t|         NomEntite        |  CodeEntite |\n");
  printf("\t__________________________________________\n");

  gen = list_mc;
  gen = gen->suiv;
  while (gen != NULL)
  { 
    printf("\t|%25s |%12s | \n",gen->name, gen->code);
    gen = gen->suiv;
  }

  printf("\n/***************Table des symboles separateurs*************/\n");
  printf("\t__________________________________________\n");
  printf("\t|         NomEntite        |  CodeEntite |\n");
  printf("\t__________________________________________\n");

  gen = list_sep;
  gen = gen->suiv; 
  while(gen != NULL)
  { 
    printf("\t|%25s |%12s | \n",gen->name,gen->code);
    gen = gen->suiv;
  }

}



sauver_idf(char id[]) {
  strcpy(sauve[pos],id);
  pos++;
}


maj_type_idf(char type[]) {
  int i;

 for (i = 0; i < pos; i++)
 {
   modifier_type(sauve[i],type);
 }
 
   for (i = 0; i < 20; i++)
  {
    strcpy(sauve[i],"\0");
  }
  pos = 0;
}

modifier_type(char entite[],char type[]){
  int i;
  gen = list_idf_cst;
  gen = gen->suiv;
  while (gen != NULL)
  {
    if ((strcmp(entite,gen->name) ==0) && !(doubledecl(entite))) strcpy(gen->type,type);
    gen = gen->suiv;
  }

}

int doubledecl(char entite[]){
  elt* gen2 = list_idf_cst;
  gen2 = gen2->suiv;
  while (gen2 != NULL)
  {
    if ((strcmp(entite,gen2->name) ==0) && strcmp(gen2->type," ")!=0) {
      return 1;
    }
    gen2 = gen2->suiv;
  }
  return 0;
}

int nonintial (char entite[]){
  elt* gen2 = list_idf_cst;
  gen2 = gen2->suiv;
  while (gen2 != NULL)
  { if ((strcmp("CONST",gen2->type) !=0)){ 
      if ((strcmp(entite,gen2->name) ==0) && (gen2->val < -32768.0 || gen2->val > 32767.0) ) {
        return 1;
      } 
    }
    gen2 = gen2->suiv;
  }
  return 0;
}

int nondeclare (char entite[]){
  elt* gen2 = list_idf_cst;
  gen2 = gen2->suiv;
  while (gen2 != NULL)
  {
    if ((strcmp(entite,gen2->name) ==0) && (strcmp(gen2->type," ")==0)) {
      return 1;
    }
    gen2 = gen2->suiv;
  }
  return 0;
}

int const_check(char entite[]) {
  elt* gen2 = list_idf_cst;
  gen2 = gen2->suiv;
  while (gen2 != NULL)
  {
    if ((strcmp(entite,gen2->name) ==0) && (strcmp(gen2->type,"CONST")==0)) {
      return 1;
    }
    gen2 = gen2->suiv;
  }
  return 0;
}

char* type_idf (char entite[]) {
  elt* gen2 = list_idf_cst;
  if (!(nondeclare(entite))){
      while (gen2 != NULL)
    {
      if ((strcmp(entite,gen2->name)==0)) {return gen2->type;}
      gen2 = gen2->suiv;
    }
  }
  else {printf("Erreur idf \"%s\" non declare : Ligne %d Col %d\n",entite,yylineo,col);return 0;}
}