#include<stdio.h>
#include<stdlib.h>

int isMaxHeap(int* a, int root, int M);
int isMinHeap(int* a, int root, int M);
void postOrder(int* a, int root, int M);
int main()
{
    int N, M;
    int i, j;
    int *a;
    scanf("%d %d", &N, &M);
    for(i = 0;i < N;i++)
    {
        a = (int*)malloc((M+1)*sizeof(int));
        for(j = 1; j <= M;j++)
        {
            scanf("%d", &a[j]);
        }
        if(isMaxHeap(a, 1, M))
        {
            printf("Max Heap\n");
        }
        else if(isMinHeap(a, 1, M))
        {
            printf("Min Heap\n");
        }
        else
        {
            printf("Not Heap\n");
        }
        postOrder(a, 2*1, M);
        postOrder(a, 2*1+1, M);
        printf("%d\n", a[1]);
        free(a);
    }
}

int isMaxHeap(int* a, int root, int M)
{
    if(root >= M)
    {
        return 1;
    }
    if(!isMaxHeap(a, 2*root, M) || !isMaxHeap(a, 2*root+1, M))
    {
        return 0;
    }
    if(2*root <= M && a[root] < a[2*root])
    {
        return 0;
    }
    if(2*root+1 <= M && a[root] < a[2*root + 1])
    {
        return 0;
    }
    return 1;
}

int isMinHeap(int* a, int root, int M)
{
    if(root >= M)
    {
        return 1;
    }
    if(!isMinHeap(a, 2*root, M) || !isMinHeap(a, 2*root+1, M))
    {
        return 0;
    }
    if(2*root <= M && a[root] > a[2*root])
    {
        return 0;
    }
    if(2*root+1 <= M && a[root] > a[2*root + 1])
    {
        return 0;
    }
    return 1;
}

void postOrder(int*a ,int root, int M)
{
    if(root > M)
    {
        return;
    }
    postOrder(a, root*2, M);
    postOrder(a, root*2+1, M);
    printf("%d ", a[root]);
}