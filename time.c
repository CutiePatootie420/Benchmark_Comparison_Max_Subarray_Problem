#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmarking.h"
int make_it_work()
{

    double brute_time;
    double recursive_time;
    int X=10000;
    int batch;
    volatile double x;
    volatile double y;
    for(int i=1;i<300;i++)
    {
        int *arr=malloc(sizeof(int)*i);
        batch=(i<50?5000:300);
        for(int j=0;j<i;j++)
        {
            arr[j]=(rand() % (2*X + 1)) - X;
        }
        clock_t start=clock();
        for(int k=0;k<batch;k++)
        {
            x=brute_force(arr,i);
        }
        clock_t end=clock();
        brute_time=(end-start)/CLOCKS_PER_SEC;
        start=clock();
        for(int k=0;k<batch;k++)
        {
            y=call(arr,i);
        }
        end=clock();
        recursive_time=(end-start)/CLOCKS_PER_SEC;
        brute_time/=batch;
        recursive_time/=batch;
        free(arr);
        if(brute_time>recursive_time)
        {
            return i;
        }
    }
}
int main()
{
    srand(time(NULL));
    long long int n=0;
    for(int i=0;i<10;i++)
    {
        n+=make_it_work();
    }
    printf("%lld",n/10);
    return 0;
}