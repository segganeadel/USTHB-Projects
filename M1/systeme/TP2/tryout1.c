#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>

const int Nbfiliere = 3;
const int Nbetud = 10;
const int Nbplaces = 5;
//const char delim = ' ';

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

void creer_structure(int *msgid, int *tamponid, int *cptid)
{

        // file message boite au lettres
    key_t key = ftok("messages", 65);
    *msgid = msgget(key, 0666 | IPC_CREAT);

    // tampon , (memoire patagé)
    key_t key1 = ftok("tampon", 65);
    *tamponid = shmget (key1, sizeof (struct case_tampon)*4, 0666 | IPC_CREAT);
    struct case_tampon * tampon= (struct case_tampon*) shmat (*tamponid,NULL,0);
    tampon = (struct case_tampon *)malloc(4 * sizeof(struct case_tampon));

    *cptid = shmget (key, sizeof (int), 0666 | IPC_CREAT);
    int *cpt = (int*) shmat (*cptid,NULL,0);
    *cpt = 0;
    printf("%d %d %d ",*msgid,*tamponid,*cptid);

    // semaphores
    sem_open("nv", O_CREAT, 0644,4);
    sem_open("np", O_CREAT, 0644,0);
    sem_open("mutex", O_CREAT, 0644,1);
}

void detruire_structure(int msgid, int tamponid, int cptid)
{
         // file message boite au lettres
        msgctl(msgid, IPC_RMID, NULL);

        // tampon , (memoire patagé)
        shmctl(tamponid, IPC_RMID, 0);
    
    // semaphores

    sem_unlink("nv");
    sem_unlink("np");
    sem_unlink("mutex");
}

void deposer(struct case_tampon requete, struct case_tampon *tampon, int *cpt, sem_t *nv, sem_t *np, sem_t *mutex)
{
    sem_wait(nv);
    sem_wait(mutex);
    /*     *tampon[cpt] = requete;
        cpt++; */
    sem_post(mutex);
    sem_post(np);
    printf("deposé ");
    // printf(" %d ",nv);
}

void prelever(struct case_tampon requete, struct case_tampon *tampon, int *cpt, sem_t *nv, sem_t *np, sem_t *mutex)
{

    sem_wait(np);
    sem_wait(mutex);
    /*
        requete = tampon[cpt - 1];
        cpt--;
    */
    sem_post(mutex);
    sem_post(nv);
    printf("prelever ");
    // printf(" %d ",*nv );
}

void gerant(int msgid, int tamponid, int cptid)
{
    struct case_tampon *tampon = (struct case_tampon *)shmat(tamponid, NULL, 0);
    int *cpt = (int *)shmat(cptid, NULL, 0);

    struct case_gere etudiants[Nbetud];
    int fini = 0;
    struct case_tampon requete;
    int message = 0;
    printf("grant bloque ");

    sem_t *nv = sem_open("nv", 0);
    sem_t *np = sem_open("np", 0);
    sem_t *mutex = sem_open("mutex", 0);

     while (fini < 2)
    {

        prelever(requete, tampon, cpt, nv, np, mutex);

        fini++;
    } 
    exit(0);
}

void etudiant_f(int msgid, int tamponid, int cptid)
{

    sem_t *nv = sem_open("nv",0);
    sem_t *np = sem_open("np",0);
    sem_t *mutex = sem_open("mutex",0);
    struct case_tampon *tampon = (struct case_tampon *)shmat(tamponid, NULL, 0);
    int *cpt = (int *)shmat(cptid, NULL, 0);

    struct case_tampon requete;

    requete.type_demande = 0;


    deposer(requete, tampon, cpt, nv, np, mutex);

    exit(0);
}

void etudiant_n(int msgid, int tamponid, int cptid)
{

    sem_t *nv = sem_open("nv", 0);
    sem_t *np = sem_open("np", 0);
    sem_t *mutex = sem_open("mutex", 0);

    struct case_tampon *tampon = (struct case_tampon *)shmat(tamponid, NULL, 0);
    int *cpt = (int *)shmat(cptid, NULL, 0);

    struct case_tampon requete;

    requete.type_demande = 0;

    deposer(requete, tampon, cpt, nv, np, mutex);

    exit(0);
}

int main(int argc, char const *argv[])
{
    int msgid;
    int tamponid;

    int cptid;
    int id;

    creer_structure(&msgid, &tamponid, &cptid);
    printf("%d %d %d ",msgid,tamponid,cptid);
    // printf("pere nv %d ",nv);

    id = fork();
    if (id == 0)
    {
        gerant(msgid, tamponid, cptid);
    }

    id = fork();
    if (id == 0)
    {
        etudiant_f(msgid, tamponid, cptid);
    }

    id = fork();
    if (id == 0)
    {
        etudiant_n(msgid, tamponid, cptid);
    }

    wait(0);
    wait(0);
    wait(0);

    detruire_structure(msgid, tamponid, cptid);

    return 0;
}
