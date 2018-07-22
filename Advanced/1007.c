#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m;
    int i, j;
    int start, end;
    int sum;
    int maxSum;
    int* a;
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    for(m = 0;m < n;m++)
    {
        scanf("%d",&a[m]);
    }
    i = j = 0;
    start = end = 0;
    sum = maxSum = 0;
    maxSum = -1;
    for(m = 0;m < n;m++)
    {
        sum += a[m];
        j = m;
        if(sum < 0)
        {
            sum = 0;
            i = m+1;
        }
        else if(sum > maxSum)
        {
            maxSum = sum;
            start = i;
            end = j;
        }
        
        
    }
    if(maxSum < 0)
    {
        maxSum = 0;
        start = 0;
        end = n-1;
    }
    printf("%d %d %d", maxSum, a[start], a[end]);
    return 0;
}
