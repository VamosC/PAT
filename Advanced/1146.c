#include<stdio.h>
#include<stdlib.h>
#define MAX 1001
typedef struct EdgeNode* Edge;
struct EdgeNode
{
    int v;
    Edge next;
};
struct vertexNode
{
    Edge next;
};
int isTopological(struct vertexNode* G, int* a, int N, int* degree);
int main()
{
    int N, M;
    int i, j;
    int v1, v2;
    int cases;
    struct vertexNode* G;
    int* a;
    int res[MAX];
    Edge cur, newNode;
    scanf("%d %d", &N, &M);
    int* degree;
    degree = (int*)malloc((N+1)*sizeof(int));
    G = (struct vertexNode*)malloc((N+1)*sizeof(struct vertexNode));
    for(i = 1;i <= N;i++)
    {
        G[i].next = NULL;
        degree[i] = 0;
    }
    for(i = 0;i < M;i++)
    {
        scanf("%d %d", &v1, &v2);
        degree[v2]++;
        cur = G[v1].next;
        newNode = (Edge)malloc(sizeof(struct EdgeNode));
        newNode->next = NULL;
        newNode->v = v2;
        if(cur == NULL)
        {
            G[v1].next = newNode;
        }
        
        else
        {
            while(cur->next)
            {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
    scanf("%d", &cases);
    int k;
    k = 0;
    a = (int*)malloc((N+1)*sizeof(int));
    for(i = 0;i < cases;i++)
    {
        for(j = 0;j < N;j++)
        {
            scanf("%d", &a[j]);
        }
        if(isTopological(G, a, N, degree))
        {
            res[k++] = i;
        }
    }
    printf("%d", res[0]);
    for(i = 1;i < k;i++)
    {
        printf(" %d", res[i]);
    }
}

int isTopological(struct vertexNode* G, int* a, int N, int* degree)
{
    int now[MAX];
    Edge cur;
    int i;
    for(i = 1;i <= N;i++)
    {
        now[i] = degree[i];
    }
    i = 0;
    while(now[a[i]] == 0 && i < N)
    {
        cur = G[a[i]].next;
        while(cur)
        {
            now[cur->v]--;
            cur = cur->next;
        }
        i++;
    }
    return i != N;
}
