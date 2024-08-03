#include <wait.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int new_sem(char path[],char token, int val){
    key_t Key = ftok(path,token);
    if(Key == -1){return -1;}
    int id= semget(Key,1,IPC_CREAT|0644);
    if (id == -1){return -2;}
    semctl(id,0,SETVAL,val);
    return id; 
}
void* new_shm(int byte_size,char path[],char token,int shflags){
    key_t key = ftok(path,token);
    if (key == -1){return (void *)-1;}
    int id = shmget(key,byte_size,shflags);
    if (id == -1){return (void *)-2;}
    void *shm = shmat(id,0,0);
    if (shm == (void *)-1){return (void *)-3;}
    return shm; 
}
void up(int semid){
    struct sembuf op_p[]={0,+1,0};
    semop(semid,op_p,1);
}
void down(int semid){
    struct sembuf op_p[] = {0,-1,0};
    semop(semid,op_p,1); 
}
