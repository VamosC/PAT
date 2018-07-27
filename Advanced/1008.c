#include<stdio.h>
#include<stdlib.h>

int up(int curtime);
int down(int curtime);
int main()
{
    int N;
    int i;
    int position;
    int curtime;
    int* request;
    scanf("%d", &N);
    request = (int*)malloc(N*sizeof(int));
    for(i = 0;i < N;i++)
    {
        scanf("%d", &request[i]);
    }
    position = 0;
    curtime = 0;
    for(i = 0;i < N;i++)
    {
        while(position != request[i])
        {
            while(position < request[i])
            {
                curtime = up(curtime);
                position++;
            }
            while(position > request[i])
            {
                curtime = down(curtime);
                position--;
            }
        }
        curtime += 5;
    }
    printf("%d", curtime);
    return 0;
}

int up(int curtime)
{
    return curtime+6;
}

int down(int curtime)
{
    return curtime+4;
}