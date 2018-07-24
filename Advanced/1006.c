#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 16
typedef struct record* records;
struct record
{
    char s[MAX];
    char start[MAX];
    char end[MAX];
};

int compare(char* m, char* n, int flag, int inout, int index);
int main()
{
    int N;
    int i;
    int in, out;
    records* t;
    in = out = 0;
    scanf("%d", &N);
    t = (records*)malloc(N*sizeof(records));
    for(i = 0;i < N;i++)
    {
        t[i] = (records)malloc(sizeof(struct record));
        scanf("%s %s %s",t[i]->s, t[i]->start, t[i]->end);
        in = compare(t[in]->start, t[i]->start, 0, in, i);
        out = compare(t[out]->end, t[i]->end, 1, out, i);
    }
    printf("%s %s",t[in]->s, t[out]->s);
    return 0;
}

int compare(char* m, char* n, int flag, int inout, int index)
{

    if(flag == 0)
    {
        if(strcmp(m, n) > 0)
        {
            inout = index;
        }
    }
    
    else
    {
        if(strcmp(m, n) < 0)
        {
            inout = index;
        }
    }
    return inout;
}