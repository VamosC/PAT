#include<stdio.h>
#include<stdlib.h>
//#define MAX 101
typedef struct treeNode* Tree;
struct treeNode
{
    Tree fisrtChild;
    Tree nextSibling;
};

int main()
{
    Tree* T;
    Tree tmp;
    int N, M;
    int i, j;
    int num;
    int child;
    int size;
    int* a;
    int aSize;
    int front, rear;
    int oldSize;
    Tree* queue;
    scanf("%d",&N);
    scanf("%d",&M);
    T = (Tree*)malloc((N+1)*sizeof(Tree));
    queue = (Tree*)malloc(N*sizeof(Tree));
    for(i = 0;i <= N;i++)
    {
        T[i] = (Tree)malloc(sizeof(struct treeNode));
        T[i]->fisrtChild = T[i]->nextSibling = NULL;
    }
    for(i = 1;i <= M;i++)
    {
        scanf("%d",&num);
        scanf("%d",&size);
        for(j = 0;j < size;j++)
        {
            tmp = T[num]->fisrtChild;
            scanf("%d", &child);
            if(tmp == NULL)
            {
                T[num]->fisrtChild = T[child];
            }
            
            else
            {
                while(tmp->nextSibling)
                {
                    tmp = tmp->nextSibling;
                }
                tmp->nextSibling = T[child];
            }
        }
    }
    front = 0;
    rear = -1;
    aSize = 0;
    a = (int*)malloc(sizeof(int));
    queue[++rear] = T[1];
    oldSize = rear - front + 1;
    while(rear - front != -1)
    {
        a[aSize] = 0;
        while(oldSize != 0)
        {
            tmp = queue[front++];
            if(tmp->fisrtChild == NULL)
            {
                a[aSize]++;
            }
            tmp = tmp->fisrtChild;
            while(tmp)
            {
                queue[++rear] = tmp;
                tmp = tmp->nextSibling;
            }
            oldSize--;
        }
        oldSize = rear - front + 1;
        aSize++;
        a = (int*)realloc(a, (aSize+1)*sizeof(int));
    }
    for(i = 0;i < aSize-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d",a[i]);
    return 0;
}
