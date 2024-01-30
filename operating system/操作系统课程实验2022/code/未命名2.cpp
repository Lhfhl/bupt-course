#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)
#define __USE_GNU
#include <sched.h>
#include <pthread.h>
#define ORANGE_MAX_VALUE 1000000
#define APPLE_MAX_VALUE 100000000
#define MSECOND 1000000
cpu_set_t mask;
int cpu_nums;

struct apple
{
    unsigned long long a;
	unsigned long long b;
	pthread_rwlock_t rwLock;
};

struct orange
{
    int a[ORANGE_MAX_VALUE];
    int b[ORANGE_MAX_VALUE];
};

int set_cpu(int i)
{
	CPU_ZERO(&mask);
	if(3 <= cpu_nums)
	{
		CPU_SET(i,&mask);
		if(-1 == sched_setaffinity(gettid(),sizeof(&mask),&mask))
		{
			return -1;
		}
	}
	return 0;
}

void* addx(void* x)
{
	if(-1 == set_cpu(1))
	{
		return NULL;
	}
	pthread_rwlock_wrlock(&((struct apple *)x)->rwLock);
	for(unsigned long long sum=0;sum<APPLE_MAX_VALUE;sum++)
	{
		((struct apple *)x)->a += sum;
	}
	pthread_rwlock_unlock(&((struct apple *)x)->rwLock);
	
	return NULL;
}
 
void* addy(void* y)
{
	if(-1 == set_cpu(2))
	{
		return NULL;
	}
	pthread_rwlock_wrlock(&((struct apple *)y)->rwLock);
	for(unsigned long long sum=0;sum<APPLE_MAX_VALUE;sum++)
	{
		((struct apple *)y)->b += sum;
	}
	pthread_rwlock_unlock(&((struct apple *)y)->rwLock);
	
	return NULL;
}
 
 
 
int main (int argc, const char * argv[]) {
	
    struct apple test;
	struct orange test1={{0},{0}};
	pthread_t ThreadA,ThreadB;
	
	if(-1 == set_cpu(0))
	{
		return -1;
	}
	
	pthread_create(&ThreadA,NULL,addx,&test);
	pthread_create(&ThreadB,NULL,addy,&test);
	
 	unsigned long long sum = 0;
	
	for(unsigned long long index=0;index<ORANGE_MAX_VALUE;index++)
	{
		sum+=test1.a[index]+test1.b[index];
	}
	
    pthread_join(ThreadA,NULL);
    pthread_join(ThreadB,NULL);
	
    return 0;
}
