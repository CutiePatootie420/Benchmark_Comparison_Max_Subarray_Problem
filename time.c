#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmarking.h"
int make_it_work()
{
    double brute_time;
    double recursive_time;
    int X=10000; // large value
    int batch;
    volatile double x;
    volatile double y;
    struct timespec start,end;
    for(int i=1;i<300;i++) // checking at how many elements recursion starts outperforming brute force
    {
        int *arr=malloc(sizeof(int)*i);
        batch=(i<50?5000:300); // more iterations for smaller sizes
        for(int j=0;j<i;j++)
        {
            arr[j]=(rand() % (2*X + 1)) - X; // random integers between -X and X
        }
        clock_gettime(CLOCK_MONOTONIC, &start);
        for(int k=0;k<batch;k++) // run multiple times to get average
        {
            x=brute_force(arr,i); 
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        brute_time=(end.tv_sec-start.tv_sec) + (end.tv_nsec-start.tv_nsec)/1e9;
        clock_gettime(CLOCK_MONOTONIC, &start);
        for(int k=0;k<batch;k++) // run multiple times to get average
        {
            y=call(arr,i);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        recursive_time=(end.tv_sec-start.tv_sec) + (end.tv_nsec-start.tv_nsec)/1e9;
        brute_time/=batch; // final average brute force time
        recursive_time/=batch; // final average recursive time
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
    printf("%lld",n/10); // final average over 10 iterations
    return 0;
}