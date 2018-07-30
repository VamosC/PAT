#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum(int* a, int l, int r);
int comp(int a, int b);
int main()
{
    int N, i;
    int* a;
    
    scanf("%d", &N);
    for(i = 0;i < N;i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, N, sizeof(int), comp);
    printf("%d %d", N%2, abs(sum(a, 0, N/2 - 1) - sum(a, N/2, N-1)));
}

int comp(int a, int b)
{
    return a - b;
}

int sum(int* a, int l, int r)
{
    int i;
    int sum;

    sum = 0;
    for(i = l;i <= r;i++)
    {
        sum += a[i];
    }
    return sum;
}