#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* stack;
    int** seq;
    int M, N, K;
    int i, j, t;
    int top;
    scanf("%d %d %d", &M, &N, & K);
    stack = (int*)malloc(M*sizeof(int));
    seq = (int**)malloc(K*sizeof(int*));
    for(i = 0;i < K;i++)
    {
        seq[i] = (int*)malloc(N*sizeof(int));
        for(j = 0;j < N;j++)
        {
            scanf("%d", &seq[i][j]);
        }
    }
    for(i = 0;i < K;i++)
    {
        top = -1;
        t = 0;
        for(j = 1;j <= N;j++)
        {
            stack[++top] = j;
            while(top != -1 && stack[top] == seq[i][t])
            {
                top--;
                t++;
            }
            if(top == M - 1)
            {
                break;
            }
        }
        if(top == -1)
        {
            printf("YES\n");
        }
        
        else
        {
            printf("NO\n");
        }
        
    }
}
