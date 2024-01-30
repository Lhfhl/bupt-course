/* FILENAME: ctl.h */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define N  8           /* 缓冲区个数 */
#define BUF_SIZE 128   /* 缓冲区大小 */

typedef struct {           /* 缓冲区队列 */
    int id;
    int head, tail;        /* 缓冲区队列的队首和队尾 */
    char buf[N][BUF_SIZE]; /* 共N个缓冲区,每缓冲区128字节 */
} QUEUE;

/* 在"生产者-消费者"问题中共需要3个信号量,创建一个信号量组，含3个信号量 */
#define NUM_SEMAPHORE  3
#define MUTEX  0         /* 第0号信号量用于缓冲区队列的互斥访问 */
#define FULL   1         /* 第1号信号量用于记录已填满数据的缓冲区个数 */
#define EMPTY  2         /* 第2号信号量用于记录空闲缓冲区个数 */

#define SEM_KEY 0x11223344  /* 信号量组的KEY */
#define SHM_KEY 0x11223355  /* 共享内存段的KEY */

#define WHITE  "\033[0;37m"
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN  "\033[1;32m"
#define PINK   "\033[1;35m"
