#include <stdio.h>
#include <time.h>
#include "benchmarking.h"

int New(int* arr, int low, int high)
{
    int mid=(low+high)/2;
    int max=-__INT_MAX__-1;
    int temp=0;
    int left=-__INT_MAX__-1;
    for(int i=mid;i>=low;i--)
    {
        temp+=arr[i];
        if(temp>left)
        {
            left=temp;
        }
    }
    temp=0;
    int right=-__INT_MAX__-1;
    for(int i=mid+1;i<=high;i++)
    {
        temp+=arr[i];
        if(temp>right)
        {
            right=temp;
        }
    }
    return left+right;

}
int Algo(int* arr, int low, int high)
{
    if(low==high)
    {
        return arr[low];
    }
    int mid=(low+high)/2;
    volatile int max=-__INT_MAX__-1;
    int temp1=Algo(arr,low,mid);
    int temp2=Algo(arr,mid+1,high);
    int temp3=New(arr,low,high);
    if(max<temp1)
    {
        max=temp1;
    }
    if(max<temp2)
    {
        max=temp2;
    }
    if(temp3>max)
    {
        max=temp3;
    }
    return max;
}
double call(int* arr, int n)
{
    volatile int x=Algo(arr,0,n-1);
    return x;
}

