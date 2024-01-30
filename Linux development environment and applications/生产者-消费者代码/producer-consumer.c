/* FILENAME: producer-consumer.c */
#include "ctl.h"

/* ------------------- IPC ---------------------------------*/
static int sem_id;
static QUEUE *q;

static void get_ipc(void)
{
    int shm_id;

    sem_id = semget(SEM_KEY, 0, 0); /* 获取已创建好的信号量组ID */
    if (sem_id == -1) {
        perror("Get Semaphore ID");
        exit(1);
    }
    shm_id = shmget(SHM_KEY, 0, 0); /* 获取共享内存段的ID */
    if (shm_id == -1) {
        perror("Get Semaphore ID");
        exit(1);
    }
    q = (QUEUE *)shmat(shm_id, 0, 0);/* 获取指向共享内存段的指针 */
    if ((int)q == -1) {
        perror("Attach Share Memory");
        exit(1);
    }
}

static void P(int sem_num) /* 对信号量组中的第sem_num号信号量执行P操作 */
{
    struct sembuf op;
    op.sem_num = sem_num;
    op.sem_op = -1;
    op.sem_flg = 0;
    if (semop(sem_id, &op, 1) == -1) {
        perror("P(semaphore)");
        exit(1);
    }
}

static void V(int sem_num)   /* 对信号量组中的第sem_num号信号量执行V操作 */
{
    struct sembuf op;
    op.sem_num = sem_num;
    op.sem_op = 1;
    op.sem_flg = 0;
    if (semop(sem_id, &op, 1) == -1) {
        perror("V(semaphore)");
        exit(1);
    }
}

/* ------------------- PRODUCER ---------------------------------*/
static void produce(char *data)
{
    int data_id;
    /* 生产过程：将生产的数据放入进程私有缓冲区buf中，一个真正的生产过    */
    /* 程可能需要较长时间,例如：一个复杂的数学计算,大型数据库检索，等等 */
    sleep(1 + random() % 5);
    P(MUTEX);
    data_id = q->id++;
    V(MUTEX);
    sprintf(data, "PRODUCER-%d ID-%d", getpid(), data_id);
}

static void producer(void)
{
    char data[BUF_SIZE]; /* 进程的私有缓冲区 */

    for(;;) {
        /* 生产过程:将新生产的数据放入进程的私有缓冲区buf中 */
        produce(data);
        P(EMPTY);
        P(MUTEX);
        /* 将已生产好的数据从进程的私有缓冲区buf,拷贝到缓冲队列的空闲缓冲区中 */
        strcpy(q->buf[q->tail], data);
        printf(PINK "Producer %d Write Buffer #%d, Data: %s"WHITE"\n",
            getpid(), q->tail, q->buf[q->tail]);
        q->tail = (q->tail + 1) % N;
        V(MUTEX);
        V(FULL);
    }
}

/* ------------------- CONSUMER ---------------------------------*/
static void consume(char *data)
{
    /* 消费过程：消费掉进程私有缓冲区buf中数据，一个真正的消费过程可能 */
    /* 需要较长时间，例如：打印或通过低速网络向远程发送数据库查询结果,等等  */
    sleep(1 + random() % 5);
}

static void consumer(void)
{
    char data[BUF_SIZE]; /* 进程的私有缓冲区 */
    for(;;) {
        P(FULL);
        P(MUTEX);
        /* 将环行队列中缓冲区内容复制到进程私有缓冲区buf中 */
        strcpy(data, q->buf[q->head]);
        printf(GREEN "Consumer %d Read  Buffer #%d, Data: %s"WHITE"\n",
            getpid(), q->head, q->buf[q->head]);
        q->head = (q->head + 1) % N;
        V(MUTEX);
        V(EMPTY);
        consume(data);   /* 消费过程:消费掉进程私有缓冲区buf中的数据 */
    }
}

/* ------------------- MAIN  ---------------------------------*/
int main(int argc,char **argv)
{
    get_ipc();

    if (strstr(argv[0], "consumer"))
        consumer();
    if (strstr(argv[0], "producer"))
        producer();
}
