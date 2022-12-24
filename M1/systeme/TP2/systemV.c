#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

#ifdef __linux
#define MSG_R 0400
#define MSG_W 0200
#endif

typedef struct
{
    int TReq;
    int nom;
    char Tetud;
    float moyenne;
    int filiere;
} requete;

typedef struct
{
    long mtype;
    int type;
    int filiere;
} reponse;

typedef struct
{
    int nom;
    char Tetud;
    float moyenne;
    int filiere1;
    int filiere2;
    int filiere3;
    int Nbdesist;
} case_gere;

typedef struct
{
    char Tetud;
    int Trep;
    int nom;
    float moyenne;
    int filiere;
} case_etudiant;

const int Fini = 0;
const int Dinscrit = 1;
const int Desist = 2;

const int Noninscrit = 0;
const int Inscrit = 1;
const int Exclu = 2;

const char EtudF = 'F';
const char EtudN = 'N';

case_gere Tab_affec[50];
case_etudiant Tab_etudF[50];
case_etudiant Tab_etudN[50];

#define Nbetud  6
#define places 5
#define Nbflieres 3

const int max1 = 13.00;
const int max2 = 12.00;
const int max3 = 10.40;

const float max[Nbflieres] = {max1, max2, max3};
int Nbplaces[Nbflieres] = { [0 ... Nbflieres-1] = places};

int nv;
int np;
int mutex;
int shmid;
int msqid;
int n = 4;
int cptid;
int *q, *t;

int sem_create(key_t cle, int initval)
{
    int semid;
    union semun
    {
        int val;
        struct semid_ds *buf;
        ushort *array;
    } arg_ctl;

    semid = semget(ftok("systemV.c", cle), 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semid == -1)
    {
        semid = semget(ftok("systemV.c", cle), 1, 0666);
        if (semid == -1)
        {
            perror("Erreur semget()");
            exit(1);
        }
    }
    arg_ctl.val = initval;
    if (semctl(semid, 0, SETVAL, arg_ctl) == -1)
    {
        perror("Erreur initialisation semaphore");
        exit(1);
    }
    return (semid);
}

void P(int semid)
{
    struct sembuf sempar;
    sempar.sem_num = 0;
    sempar.sem_op = -1;
    sempar.sem_flg = SEM_UNDO;

    if (semop(semid, &sempar, 1) == -1)
    {
        perror("Erreur operation P");
        printf(" semid: %d\n", semid);
    }
}

void V(int semid)
{

    struct sembuf sempar;
    sempar.sem_num = 0;
    sempar.sem_op = 1;
    sempar.sem_flg = SEM_UNDO;

    if (semop(semid, &sempar, 1) == -1)
    {
        perror("Erreur operation V semid");
        printf(" semid: %d\n", semid);
    }
}

void sem_delete(int semid)
{
    if (semctl(semid, 0, IPC_RMID, 0) == -1)
        perror("Erreur dans destruction semaphore");
}

void preparerF(requete *req, char *line)
{
    char *token = strtok(line, ",");
    req->nom = atoi(token);
    req->Tetud = 'F';
    req->TReq = Dinscrit;
    token = strtok(NULL, ",");
    req->moyenne = atof(token);
    token = strtok(NULL, ",");
    req->filiere = atoi(token);
}

void preparerN(requete *req, char *line)
{
    char *token = strtok(line, ",");
    req->nom = atoi(token);
    req->Tetud = 'N';
    req->TReq = Dinscrit;
    token = strtok(NULL, ",");
    req->moyenne = atof(token);
    req->filiere = 0;
}

void deposer(requete *req, requete *tampon)
{
    tampon[*q] = *req;
    *q = (*q + 1) % n;
}

void prelever(requete *req, requete *tampon)
{
    *req = tampon[*t];
    *t = (*t + 1) % n;
}

void memoriser(case_etudiant *Tab_etudiant, int i, requete req, reponse rep)
{
    Tab_etudiant[i].nom = req.nom;
    Tab_etudiant[i].moyenne = req.moyenne;
    Tab_etudiant[i].Tetud = req.Tetud;

    Tab_etudiant[i].filiere = rep.filiere;
    Tab_etudiant[i].Trep = rep.type;
}

void memoriser1(case_etudiant *Tab_etudiant, int i, requete req, reponse rep)
{
    Tab_etudiant[i].nom = req.nom;
    Tab_etudiant[i].moyenne = req.moyenne;
    Tab_etudiant[i].Tetud = req.Tetud;
    Tab_etudiant[i].filiere = req.filiere;

    Tab_etudiant[i].Trep = rep.type;
}

void memoriser2(case_etudiant *Tab_etudiant, int i, requete req, reponse rep)
{
    Tab_etudiant[i].filiere = rep.filiere;
    Tab_etudiant[i].Trep = rep.type;
}

void memoriser3(case_etudiant *Tab_etudiant, int i, requete req, reponse rep)
{
    Tab_etudiant[i].filiere = rep.filiere;
    Tab_etudiant[i].Trep = rep.type;
}

int assigner_moyenne(requete req)
{
    for (int i = 0; i < Nbflieres; i++)
    {
        if ((Nbplaces[i] > 0) && (req.moyenne >= max[i]))
        {
            Nbplaces[i]--;
            return i+1;  //retourner la filiere affectee index+1
        }
    }
    return 0;
}

int assigner_choix(requete req)
{
    if ((Nbplaces[req.filiere-1] > 0) && (req.moyenne >= max[req.filiere-1]))
    {
        Nbplaces[req.filiere-1]--;
        return req.filiere-1;
    }
    return assigner_moyenne(req);
}

reponse faire_inscriptionF1(case_gere *Tab_affec, int i, requete req)
{
    reponse rep;
    Tab_affec[i].nom = req.nom;
    Tab_affec[i].moyenne = req.moyenne;
    Tab_affec[i].Tetud = req.Tetud;
    Tab_affec[i].filiere1 = assigner_choix(req);
    Tab_affec[i].Nbdesist = 0;

    if (Tab_affec[i].filiere1 == 0)
    {
        rep.type = Noninscrit;
    }
    else
    {
        rep.type = Inscrit;
    }

    rep.filiere = Tab_affec[i].filiere1;
    rep.mtype = 1;

    return rep;
}

reponse faire_inscriptionF2(case_gere *Tab_affec, int i, requete req)
{
    reponse rep;
    Tab_affec[i].filiere2 = assigner_choix(req);

    if (Tab_affec[i].filiere2 == 0)
    {
        rep.type = Noninscrit;
    }
    else
    {
        rep.type = Inscrit;
    }
    
    rep.filiere = Tab_affec[i].filiere2;
    rep.mtype = 1;

    if (Tab_affec[i].filiere2 != 0)
    {
        Nbplaces[Tab_affec[i].filiere1-1]++;
    }

    return rep;
}

reponse faire_inscriptionF3(case_gere *Tab_affec, int i, requete req)
{
    reponse rep;
    Tab_affec[i].filiere3 = assigner_choix(req);

    if (Tab_affec[i].filiere3 == 0)
    {
        rep.type = Noninscrit;
    }
    else
    {
        rep.type = Inscrit;
    }

    rep.filiere = Tab_affec[i].filiere3;
    rep.mtype = 1;

    if (Tab_affec[i].filiere3 != 0)
    {
        Nbplaces[Tab_affec[i].filiere2 - 1]++;
    }

    return rep;
}

int desist()
{
    return rand() % 2;
}

reponse faire_inscriptionN(case_gere *Tab_affec, int i, requete req)
{
    reponse rep;

    Tab_affec[i].nom = req.nom;
    Tab_affec[i].moyenne = req.moyenne;
    Tab_affec[i].Tetud = req.Tetud;
    Tab_affec[i].filiere1 = req.filiere;
    Tab_affec[i].Nbdesist = 0;
    Tab_affec[i].filiere1 = assigner_moyenne(req);
    
    if (Tab_affec[i].filiere1 == 0)
    {
        rep.type = Noninscrit;
    }
    else
    {
        rep.type = Inscrit;
    }

    rep.filiere = Tab_affec[i].filiere1;
    rep.mtype = 2;


    return rep;
}

int chercher_fiche(case_gere *Tab_affec, requete req, int len)
{

    for (int i = 0; i < len; i++)
    {
        if (Tab_affec[i].nom == req.nom)
        {
            return i;
        }
    }
}

reponse preparer_exclu(case_gere *Tab_affec, int i, requete req)
{
    reponse rep;

    rep.type = Exclu; //exclu
    rep.mtype = 1;


    return rep;
}

void creer_structure()
{
    char *path = "systemV.c";

    if ((msqid = msgget(ftok(path, (key_t)10),
                        IPC_CREAT | IPC_EXCL | MSG_R | MSG_W)) == -1)
    {
        perror("Echec de msgget");
        exit(1);
    }

    if ((shmid = shmget(ftok(path, (key_t)20), sizeof(requete) * n,
                        IPC_CREAT | IPC_EXCL | SHM_R | SHM_W)) == -1)
    {
        perror("Echec de shmget");
        exit(1);
    }

    int *cpt;

    if ((cptid = shmget(ftok(path, (key_t)60), sizeof(int) * 2,
                        IPC_CREAT | IPC_EXCL | SHM_R | SHM_W)) == -1)
    {
        perror("Echec de shmget q t");
        exit(1);
    }

    if ((cpt = (int *)shmat(cptid, 0, 0)) == (void *)-1)
    {
        perror("attachement impossible q t ");
        exit(1);
    }

    q = &cpt[0];
    *q = 0;

    t = &cpt[1];
    *t = 0;

    nv = sem_create(30, 4);
    np = sem_create(5, 0);
    mutex = sem_create(50, 1);
}

void detruire_structure()
{
    msgctl(msqid, IPC_RMID, 0);
    shmctl(shmid, IPC_RMID, 0);
    shmctl(cptid, IPC_RMID, 0);
    sem_delete(nv);
    sem_delete(np);
    sem_delete(mutex);
}

void print_tab_gere(case_gere *Tab_affec, int len)
{
    printf("Tab gere \n");
    for (int i = 0; i < len; i++)
    {
        printf("Nom: %d Moyenne: %.2f Filiere1: %d Filiere2: %d Filiere3: %d Nbdesist: %d Tetud: %c \n", Tab_affec[i].nom, Tab_affec[i].moyenne, Tab_affec[i].filiere1, Tab_affec[i].filiere2, Tab_affec[i].filiere3, Tab_affec[i].Nbdesist, Tab_affec[i].Tetud);
    }
}

void print_tab_etud(case_etudiant *Tab_Etudiant, int len)    
{
    printf("Tab etudiant %c\n",Tab_Etudiant[0].Tetud);
    for (int i = 0; i < len; i++)
    {
        printf("Nom: %d Moyenne: %.2f Filiere: %d Tetud:%c Trep: %d\n", Tab_Etudiant[i].nom, Tab_Etudiant[i].moyenne, Tab_Etudiant[i].filiere, Tab_Etudiant[i].Tetud, Tab_Etudiant[i].Trep);
    }
}

void affect()
{
    requete req;
    reponse rep;
    requete *tampon;
    int Nbfini = 0;
    int Nbdesist = 0;
    int index = 0;
    int i = 0;

    if ((tampon = (requete *)shmat(shmid, 0, 0)) == (void *)-1)
    {
        perror("attachement impossible affect");
        exit(1);
    }
 
    while (Nbfini < 2)
    {
        P(np);
        P(mutex);
        prelever(&req, tampon);
        V(mutex);
        V(nv);
        if (req.TReq != Fini)
        {
            if (req.Tetud == EtudF)
            {
                if (req.TReq == Inscrit)
                {
                    rep = faire_inscriptionF1(Tab_affec, i, req);
                    i++;
                }
                else
                {
                    index = chercher_fiche(Tab_affec, req, i);
                    Tab_affec[index].Nbdesist++;
                    Nbdesist = Tab_affec[index].Nbdesist;
                    if (Nbdesist == 1)
                    {
                        rep = faire_inscriptionF2(Tab_affec, index, req);
                    }
                    else
                    {
                        if (Tab_affec[index].filiere1 == Tab_affec[index].filiere2)
                        {
                            rep = preparer_exclu(Tab_affec, index, req);
                        }
                        else
                        {
                            rep = faire_inscriptionF3(Tab_affec, index, req);
                        }
                    }
                }
            }
            else
            {
                rep = faire_inscriptionN(Tab_affec, i, req);
                i++;
            }
            if (msgsnd(msqid, &rep, sizeof(reponse), 0) == -1)
            {
                perror("Echec de msgsnd\n");
            }
        }
        else
        {
            Nbfini++;
        }
    }
    print_tab_gere(Tab_affec, i);
    exit(0);
}

void etudiantF()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    requete req;
    reponse rep;
    requete *tampon;

    if ((tampon = (requete *)shmat(shmid, 0, 0)) == (void *)-1)
    {
        perror("attachement impossible etudiantN");
        exit(1);
    }

    fp = fopen("./Etudiants_F.txt", "r");
    if (fp == NULL)
        exit(1);

    for (int i = 0; i < Nbetud; i++)
    {
        getline(&line, &len, fp);
        preparerF(&req, line);
        P(nv);
        P(mutex);
        deposer(&req, tampon);
        V(mutex);
        V(np);
        if (msgrcv(msqid, &rep, sizeof(reponse), 1, 0) == -1)
        {
            printf("msgrcv failed with error \n");
        }
        memoriser1(Tab_etudF, i, req, rep);
        if ((rep.type = Inscrit) && (req.filiere != rep.filiere))
        {
            if (desist())
            {
                req.TReq = Desist; // envoyer la même requête
                P(nv);
                P(mutex);
                deposer(&req, tampon);
                V(mutex);
                V(np);
                if (msgrcv(msqid, &rep, sizeof(reponse), 1, 0) == -1)
                {
                    printf("msgrcv failed with error \n");
                }
                memoriser2(Tab_etudF, i, req, rep);
                if ((rep.type == Inscrit) && (req.filiere != rep.filiere))
                {
                    if (desist())
                    {
                        req.TReq = Desist; // envoyer la même requête
                        P(nv);
                        P(mutex);
                        deposer(&req, tampon);
                        V(mutex);
                        V(np);
                        if (msgrcv(msqid, &rep, sizeof(reponse), 1, 0) == -1)
                        {
                            printf("msgrcv failed with error \n");
                        }
                        memoriser3(Tab_etudF, i, req, rep);
                    }
                }
            }
        }
    }

    req.TReq = Fini;
    P(nv);
    P(mutex);
    deposer(&req, tampon);
    V(mutex);
    V(np);
    print_tab_etud(Tab_etudF, Nbetud);
    fclose(fp);
    exit(0);
}

void etudiantN()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    requete req;
    reponse rep;
    requete *tampon;
    int length = sizeof(reponse);

    if ((tampon = (requete *)shmat(shmid, 0, 0)) == (void *)-1)
    {
        perror("attachement impossible etudiantN");
        exit(1);
    }

    fp = fopen("./Etudiants_N.txt", "r");
    if (fp == NULL)
        exit(1);

    for (int i = 0; i < Nbetud; i++)
    {

        getline(&line, &len, fp);
        preparerN(&req, line);
        P(nv);
        P(mutex);
        deposer(&req, tampon);
        V(mutex);
        V(np);
        if (msgrcv(msqid, &rep, sizeof(reponse), 2, 0) == -1)
        {
            printf("msgrcv failed with error \n");
        }
        memoriser(Tab_etudN, i, req, rep);
    }

    req.TReq = Fini;
    P(nv);
    P(mutex);
    deposer(&req, tampon);
    V(mutex);
    V(np);
    print_tab_etud(Tab_etudN, Nbetud);
    fclose(fp);
    exit(0);
}

int main(int argc, char const *argv[])
{
    int id;

    creer_structure();

    id = fork();
    if (id == 0)
    {
        affect();
    }

    id = fork();
    if (id == 0)
    {
        etudiantF();
    }

    id = fork();
    if (id == 0)
    {
        etudiantN();
    }

    wait(0);
    wait(0);
    wait(0);

    detruire_structure();


    return 0;
}
