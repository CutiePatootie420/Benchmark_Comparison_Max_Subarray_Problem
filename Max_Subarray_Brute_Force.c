#include <stdio.h>
#include <time.h>
#include "benchmarking.h"

double brute_force(int* arr,int n)
{
    volatile int max=-__INT_MAX__-1;
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            temp=arr[j]-arr[i];
            if(temp>max)
            {
                max=temp;
            }
        }
    }
    return max;

}
