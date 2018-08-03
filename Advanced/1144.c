#include<stdio.h>
#include<stdlib.h>
int compare(const int*a, const int* b);
int main()
{
    int N;
    int* a;
    int i;
    scanf("%d", &N);
    a = (int*)malloc(N*sizeof(int));
    for(i = 0;i < N;i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, N, sizeof(int), compare);
    int x = 1;
    for(i = 0;i < N;i++)
    {
        if(a[i] < x);
        else if(a[i] == x)
        {
            x++;
        }
        else
        {
            break;
        }
    }
    printf("%d",x);   
}

int compare(const int*a, const int* b)
{
    return *a - *b;
}