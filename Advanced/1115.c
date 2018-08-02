#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode* Tree;
struct treeNode
{
    int val;
    Tree left;
    Tree right;
};
Tree buildTree(int N);
Tree insert(int val, Tree T);
int main()
{
    int N;
    int n1, n2;
    Tree T;
    Tree p;
    Tree* queue;
    int front, rear;
    int oldSize;
    scanf("%d", &N);
    T = buildTree(N);
    n1 = 0;
    n2 = 0;
    front = 0;
    rear = -1;
    queue = (Tree*)malloc((N+1)*sizeof(Tree));
    queue[++rear] = T;
    oldSize = rear - front;
    p = NULL;
    while(rear - front != -1)
    {
        n2 = n1;
        n1 = oldSize + 1;
        while(oldSize != -1)
        {
            p = queue[front++];
            if(p->left)
            {
                queue[++rear] = p->left;
            }
            if(p->right)
            {
                queue[++rear] = p->right;
            }
            oldSize--;
        }
        oldSize = rear - front;
    }
    printf("%d + %d = %d", n1, n2, n1 + n2);
}

Tree buildTree(int N)
{
    int i;
    int val;
    Tree T;
    T = NULL;
    for(i = 0;i < N;i++)
    {
        scanf("%d", &val);
        T = insert(val, T);
    }
    return T;
}

Tree insert(int val, Tree T)
{
    if(T == NULL)
    {
        T = (Tree)malloc(sizeof(struct treeNode));
        T->left = T->right = NULL;
        T->val = val;
    }
    
    else
    {
        if(val <= T->val)
        {
            T->left = insert(val, T->left);
        }
        else
        {
            T->right = insert(val, T->right);
        }
    }
    
    return T;
}
