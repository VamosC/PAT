#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
int isPrime(int N);
int main()
{
    int index;
    int s[MAX];
    int visit[MAX];
    int K;
    int i;
    int N;
    scanf("%d", &N);
    for(i = 0;i < MAX;i++)
    {
        visit[i] = 1;
        s[i] = -1;
    }
    for(i = 0;i < N;i++)
    {
        scanf("%d", &index);
        s[index] = i;
    }
    scanf("%d", &K);
    for(i = 0;i < K;i++)
    {
        scanf("%d", &index);
        if(s[index] == -1)
        {
            printf("%4d: Are you kidding?\n", index);
        }
        
        else
        {
            if(visit[index])
            {
                if(s[index] == 0)
                {
                    printf("%04d: Mystery Award\n", index);
                }
                else if(isPrime(s[index]+1))
                {
                    printf("%04d: Minion\n", index);
                }
                else
                {
                    printf("%04d: Chocolate\n", index);
                }
                visit[index] = 0;
            }
            else
            {
                printf("%04d: Checked\n", index);
            }
        }
        
    }
    return 0;
}

int isPrime(int N)
{
    int i, j;
    int a[N+1];
    
    for(i = 1;i <= N;i++)
    {
        a[i] = 1;
    }
    a[1] = 0;
    for(i = 2;i <= N;i++)
    {
        if(a[i])
        {
            j = 2;
            while(i*j <= N)
            {
                a[i*j] = 0;
                j++;
            }
        }
    }
    return a[N];
}

