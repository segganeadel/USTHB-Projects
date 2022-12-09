#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <semaphore.h>

const int Nbfiliere = 3;
const int Nbetud = 10;
const int Nbplaces = 5;
const char delim = ' ';

int msgid;
struct case_tampon *tampon;
sem_t nv;
sem_t np;
sem_t mutex;
int cpt = 0;

struct case_tampon
{
    int type_demande;
    int nom_etudiant;
    char type_etudiant;
    float moyenne;
    int filiere;
};

struct case_gere
{
    int nom_etudiant;
    char type_etudiant;
    int type_reponse;
    int nombre_de_desistement;
};

struct case_etudiant
{
    int nom_etudiant;
    char type_etudiant;
    float moyenne;
    int type_demande;
    int filiere;
};

struct reponse
{   
    long mtype;
    int type_reponse;
    char type_etudiant;
    int filiere;
};

void creer_structure()
{
    // file message boite au lettres
    key_t msgkey = ftok("progfile", 65);
    msgid = msgget(msgkey, 0666 | IPC_CREAT);
    key_t shmkey = ftok("progfile", 65);
    shmid = shmget (shmkey, sizeof (int), 0644 | IPC_CREAT);
    // tampon , (memoire patagé)
    tampon = (struct case_tampon *)malloc(4 * sizeof(struct case_tampon));

    // semaphores
    sem_init(&nv, 1, 4);
    sem_init(&np, 1, 0);
    sem_init(&mutex, 1, 1);
}

void detruire_structure()
{
    // file message boite au lettres
    msgctl(msgid, IPC_RMID, NULL);

    // tampon , (memoire patagé)
    free(tampon);

    // semaphores
    sem_destroy(&nv);
    sem_destroy(&np);
    sem_destroy(&mutex);
}

void deposer(struct case_tampon requete)
{
    sem_wait(&nv);
    sem_wait(&mutex);
    tampon[cpt] = requete;
    cpt++;
    sem_post(&mutex);
    sem_post(&np);
    printf("deposé ");
    printf(" %d ",np);  
}

void prelever(struct case_tampon requete)
{
    printf("prelever ");
    printf(" %d ",np);
    //sem_wait(&np);

/*     sem_wait(&mutex);
    requete = tampon[cpt - 1];
    
    cpt--;
    sem_post(&mutex); */
    sem_post(&nv); 
    
}

void str_to_list (char * str,char ** str_list){

    char *strtok(line, delim);
        char *ptr = strtok(str, &delim);
    while(ptr != NULL)
    {
        printf("'%s'\n", ptr);
        ptr = strtok(NULL, &delim);
    }
}

void gerant()
{
    struct case_gere etudiants[Nbetud];
    int fini = 0;
    struct case_tampon requete;
    int message = 0;
    printf("grant bloque ");
    while (fini < 2)
    {
        // comsommer du tampon
        prelever(requete);

        // si fini incrementer fini
        //printf("%d",requete.type_demande);
/*         if (requete.type_demande == 0)
            fini++;
        else
        {
            // sinon
            // si il y'a de la place envoyer ok
            // sinon envoyer complet
            // si 2emme desistement envoyer exclu
            // envoyer reponse
            msgsnd(msgid, &message, sizeof(message), 0); 
        } */
        fini++;
    } 
    exit(0);
}

void etudiant_f()
{
    struct case_tampon requete;
    int message = 0;
    int Nbetudn = 0;
    size_t len;
    char * str = NULL;
    FILE * f = fopen("./Etudiants_N.txt", "r");

    for (int i = 0; i < Nbetudn; i++)
    {
/*         printf("dkhalt");
        // lire requete

/*       getline(&str, &len, f);
        char *strtok(line, delim);
        	char *ptr = strtok(str, delim);
        while(ptr != NULL)
        {
            printf("'%s'\n", ptr);
            ptr = strtok(NULL, delim);
        } */

        // preparer requete

        // deposer dans le tampon (produire) (requete 1 ou desistement 2)
        deposer(requete);

        // recevoir(b,rep)
        msgrcv(msgid, &message, sizeof(message), 0, 0);

        // desister ou pas 2 fois max */
    }

    // envoyer fini (type demande 0)
    fclose(f);
    requete.type_demande = 0;
    deposer(requete);
    exit(0);
}

void etudiant_n()
{
    struct case_tampon requete;
    struct reponse rep;
    int Nbetudf = 0;
    int random;
    size_t len;
    char * line = NULL;
    FILE * f = fopen("./Etudiants_F.txt", "r");

    
    for (int i = 0; i < Nbetudf; i++)
    {
/*         printf("dkhalt");
        // lire requete
        getline(&line, &len, f);
        // preparer requete

        // deposer dans le tampon (produire) (requete 1 ou desistement 2)
        deposer(requete);

        // recevoir(b,rep)
        msgrcv(msgid, &rep, sizeof(rep), 0, 0);
        // desister ou pas 2 fois max

        random = rand();

        if (rep.type_reponse != 0 && random)
        {
            // si etudiant existe dans table et nombre de desistement = 2
        } */
    }

    fclose(f);
    // envoyer fini (type demande 0)
    requete.type_demande = 0;
    deposer(requete);
    exit(0);
}

int main(int argc, char const *argv[])
{
    int id;
    
    creer_structure();

    printf(" %d ",np);

    id = fork();
    if (id == 0)
        etudiant_f();

    id = fork();
    if (id == 0)
        etudiant_n();

    id = fork();
    if (id == 0)
        gerant();

    wait(0);
    wait(0);
    wait(0);

    detruire_structure();

    return 0;
}
