#include<stdio.h>
#include<stdlib.h>
#define ORANGE_MAX_VALUE 1000000
#define APPLE_MAX_VALUE 100000000
#define MSECOND 1000000
 char c[128];
struct apple
{
       unsigned long long a;
       unsigned long long b;
};
struct orange
{
       int a[ORANGE_MAX_VALUE];
       int b[ORANGE_MAX_VALUE];
};
int main(int argc,const char *argv[])
{
       struct apple test;
       struct orange test1={{0},{0}};
       for(unsigned long long sum=0;sum<APPLE_MAX_VALUE;sum++)
       {
              test.a += sum;
              test.b += sum;
       }
       unsigned long long sum=0;
       for(unsigned long long index=0;index<ORANGE_MAX_VALUE;index++)
       {
              sum+=test1.a[index]+test1.b[index];
       }
       return 0;
}
