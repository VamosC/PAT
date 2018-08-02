#include<stdio.h>
#include<stdlib.h>

typedef struct edgeNode* Edge;
struct vertexNode
{
    int degree;
    Edge next;
};
struct edgeNode
{
    int v;
    Edge next;
};
int main()
{
    int N, M;
    int i;
    int v;
    int v1, v2;
    Edge cur;
    Edge newNode;
    int odd;
    struct vertexNode* G;
    int* visit;
    int* queue;
    int flag;
    int front, rear;
    flag = 1;
    scanf("%d %d", &N, &M);
    G = (struct vertexNode*)malloc((N+10)*sizeof(struct vertexNode));
    queue = (int*)malloc((N+2)*sizeof(int));
    visit = (int*)malloc((N+2)*sizeof(int));
  
    for(i = 1;i <= N;i++)
    {
        visit[i] = 0;
    }
    for(i = 1; i <= N;i++)
    {
        G[i].degree = 0;
        G[i].next = NULL;
    }
    for(i = 0;i < M;i++)
    {
        scanf("%d %d", &v1, &v2);
        cur = G[v1].next;
        newNode = (Edge)malloc(sizeof(struct edgeNode));
        newNode->v = v2;
        newNode->next = NULL;
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
        G[v1].degree++;
        cur = G[v2].next;
        newNode = (Edge)malloc(sizeof(struct edgeNode));
        newNode->v = v1;
        newNode->next = NULL;
        if(cur == NULL)
        {
            G[v2].next = newNode;
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
        G[v2].degree++;
    }
    front = 0;
    rear = -1;
    visit[1] = 1;
    queue[++rear] = 1;
    while(rear - front != -1)
    {
        v = queue[front++];
        cur = G[v].next;
        while(cur)
        {
            if(!visit[cur->v])
            {
                visit[cur->v] = 1;
                queue[++rear] = cur->v;
            }
            cur = cur->next;
        }
    }
    for(i = 1;i <= N;i++)
    {
        if(!visit[i])
        {
            flag = 0;
        }
    }
    odd = 0;
    for(i = 1;i <= N;i++)
    {
        if(G[i].degree % 2 == 1)
        {
            odd++;
        }
    }
    printf("%d", G[1].degree);
    for(i = 2;i <= N;i++)
    {
        printf(" %d", G[i].degree);
    }
    printf("\n");
    if(odd == 0 && flag)
    {
        printf("Eulerian");
    }
    else if(odd == 2 && flag)
    {
        printf("Semi-Eulerian");
    }
    else
    {
        printf("Non-Eulerian");
    }
    return 0;
}
