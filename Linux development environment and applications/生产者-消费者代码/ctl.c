/* FILENAME: ctl.c */
#include "ctl.h"

static void create_ipc(void)   /* 创建信号量组和共享内存段 */
{
    int sem_id, shm_id;
    struct sembuf ops[2];
    QUEUE *q;

    sem_id = semget(SEM_KEY, NUM_SEMAPHORE, IPC_CREAT | IPC_EXCL | 0666);
    if (sem_id == -1) {    /* 不能创建新信号量组时,给出错误信息 */
        perror("Create Semaphores");
        exit(1);
    } else {  /* 初始化信号量METEX和EMPTY */
        printf("Create Semaphores: OK\n");
        ops[0].sem_num = MUTEX;
        ops[0].sem_op = 1;
        ops[0].sem_flg = 0;
        ops[1].sem_num = EMPTY;
        ops[1].sem_op = N;
        ops[1].sem_flg = 0;
        if (semop(sem_id, ops, 2) == -1) {
            perror("semop");
            exit(1);
        } else {
            printf("Initialize Semaphores: OK\n");
        }
    }

    shm_id = shmget(SHM_KEY, sizeof(QUEUE), IPC_CREAT | IPC_EXCL | 0666);
    if (shm_id == -1) { /* 创建共享内存段 */
        perror("Create Share Memory");
        exit(1);
    } else {
        printf("Create Share memory: OK\n");
        q = (QUEUE *)shmat(shm_id, 0, 0); /* 获取指向共享内存段的指针 */
        if (q == (QUEUE *)-1) {
            perror("Attach Share Memory");
            exit(1);
        } else { /* 初始化缓冲区队列 */
            q->head = q->tail = 0;
            printf("Initialize QUEUE: OK\n");
        }
    }
}

static void remove_ipc(void) /* 删除信号量组和共享内存段 */
{
    int sem_id, shm_id;

    sem_id = semget(SEM_KEY, 0, 0); /* 根据KEY获取已存在的信号量组的ID */
    if (sem_id == -1) 
        perror("Get Semaphores");
    else {
        if (semctl(sem_id, 0, IPC_RMID, 0) == -1)  /* 删除信号量组 */
            perror("Remove Semaphores");
        else
            printf("Remove Semaphores: OK\n");
    }

    shm_id = shmget(SHM_KEY, 0, 0);  /* 根据KEY获取已存在的共享内存段的ID */
    if (shm_id == -1) 
        perror("Get Share Memory");
    else {
        if(shmctl(shm_id, IPC_RMID, 0) == -1)  /* 删除共享内存段 */
            perror("Remove Share Memory");
        else
            printf("Remove Share Memory: OK\n");
    }
}

int main(int argc,char **argv)
{
    if (argc > 1 && strcmp(argv[1], "create") == 0)
        create_ipc();
    else if (argc > 1 && strcmp(argv[1],"remove") == 0)
        remove_ipc();
    else /* 打印该命令的使用方法 */
        printf("Usage: %s { create | remove }\n", argv[0]);
}

