#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define N 5
#define ESQUERDA(i) ((i+N-1)%N)
#define DIREITA(i) ((i+1)%N)
#define PENSANDO 0
#define COM_FOME 1
#define ALIMENTANDO 2
#define SEMID 3565

union semun {
int val;
struct semid_ds *buf;
unsigned short *array;
struct seminfo *__buf;
};

int filosofos;
int estados;
int mutex;

int cria_semaforo(key_t id, int nsem) {
  int semid;
  semid = semget(id, nsem, 0777 | IPC_CREAT);
  if(semid < 0) perror("semget()");
  return semid;
}


int get_semaforo(key_t id, int nsem) {
return(semget(id, nsem, 0777)); }

void set_sem_valor(int semid, int val, int indice) {
union semun arg; arg.val = val;
if(semctl(semid, indice, SETVAL, arg) < 0) perror("semctl()"); }

int get_sem_valor(int semid, int indice) {
union semun arg;
return(semctl(semid, indice, GETVAL, arg)); }


void down(int semid, int indice) {
struct sembuf psem[1];
psem[0].sem_num= indice;
psem[0].sem_op = -1;
psem[0].sem_flg = SEM_UNDO;
semop(semid, psem, 1); }

void up(int semid, int indice) {
struct sembuf psem[1];
psem[0].sem_num = indice;
psem[0].sem_op = 1;
psem[0].sem_flg = SEM_UNDO;
semop(semid, psem, 1); }


void pensa(int i) {
int tempo;
tempo = rand() % 10;
printf("\nFilosofo %d pensando por %d s.", i, tempo);
fflush(stdout);
sleep(tempo);
}

void alimenta(int i) {
int tempo;
tempo = rand() % 10;
printf("\n>>>>>Filosofo %d se alimentando por %d s.", i, tempo); fflush(stdout);
sleep(tempo); }


void testa(int i) {
down(mutex, 0);
if(get_sem_valor(estados, i) == COM_FOME &&
get_sem_valor(estados, ESQUERDA(i)) != ALIMENTANDO &&
get_sem_valor(estados, DIREITA(i)) != ALIMENTANDO) {
set_sem_valor(estados, ALIMENTANDO, i); up(filosofos, i);
}
up(mutex, 0); }

void apanha_palitos(int i) {
set_sem_valor(estados, COM_FOME, i);
testa(i);
down(filosofos, i);
}


void devolve_palitos(int i) {
set_sem_valor(estados, PENSANDO, i);
testa(ESQUERDA(i));
testa(DIREITA(i));
}

int main(int argc, char** argv) {
int i, k;
if(argc != 2) {
printf("Uso: %s numero -do-filosofo\n", argv[0]);
exit (1);
}
i = atoi(argv[1]);
srand(1007 * i);

if(i == 0) {
filosofos = cria_semaforo(SEMID, N);
estados = cria_semaforo(SEMID+1, N);
mutex = cria_semaforo(SEMID+2, 1);
set_sem_valor(mutex, 1, 0);
  for(k = 0; k < N; k++) {
    set_sem_valor(filosofos, 0, k);
    set_sem_valor(estados, PENSANDO, k);
    }
}
else {
filosofos = get_semaforo(SEMID, N);
estados = get_semaforo(SEMID+1, N);
mutex = get_semaforo(SEMID+2, 1);
}


printf("\nFilosofo %d iniciando sua rotina ...", i);
fflush(stdout );
while(1) {
pensa(i);
apanha_palitos(i);
alimenta(i);
devolve_palitos(i); }
}
