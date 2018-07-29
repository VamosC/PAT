#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode* Tree;
struct TreeNode
{
    int val;
    Tree left;
    Tree right;
};
Tree buildTree(Tree T, int* post, int* in, int l, int r, int m, int n);
int main()
{
    int N;
    int i;
    Tree T;
    Tree p;
    int* post;
    int* in;
    Tree* queue;
    int front, rear;
    T = NULL;
    scanf("%d", &N);
    post = (int*)malloc(N*sizeof(int));
    in = (int*)malloc(N*sizeof(int));
    queue = (Tree*)malloc(N*sizeof(Tree));
    front = 0;
    rear = -1;
    for(i = 0;i < N;i++)
    {
        scanf("%d", &post[i]);
    }
    for(i = 0;i < N;i++)
    {
        scanf("%d", &in[i]);
    }
    T = buildTree(T, post, in, 0, N-1, 0, N-1);
    printf("%d", T->val);
    if(T->left)
    {
        queue[++rear] = T->left;
    }
    if(T->right)
    {
        queue[++rear] = T->right;
    }
    while(rear - front != -1)
    {
        p = queue[front++];
        printf(" %d",p->val);
        if(p->left)
        {
            queue[++rear] = p->left;
        }
        if(p->right)
        {
            queue[++rear] = p->right;
        }
    }
    return 0;
}

Tree buildTree(Tree T, int* post, int* in, int l, int r, int m, int n)
{
    int i;
    if(l > r)
    {
        return NULL;
    }
    
    if(T == NULL)
    {
        T = (Tree)malloc(sizeof(struct TreeNode));
        T->val = post[r];
        T->left = T->right = NULL;
    }
    for(i = m;i <= n;i++)
    {
        if(in[i] == post[r])
        {
            break;
        }
    }
    T->left = buildTree(T->left, post, in, l, l+i-1-m, m, i-1);
    T->right = buildTree(T->right, post, in, r-1-n+(i+1), r-1, i+1, n);
    return T;
}
