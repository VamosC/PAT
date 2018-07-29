#include<stdio.h>
#include<stdlib.h>

typedef struct avlNode* avlTree;
struct avlNode
{
    int val;
    avlTree left;
    avlTree right;
    int height;
};
int Height(avlTree T);
avlTree LL(avlTree k);
avlTree LR(avlTree k);
avlTree RL(avlTree k);
avlTree RR(avlTree k);
avlTree insert(avlTree T, int val);
avlTree buildTree(int N);
void levelTraversal(avlTree T, int* a, int* flag, int N);
int has2Child(avlTree T);
int has1Child(avlTree T);
int max(int a, int b);
int main()
{
    avlTree T;
    int flag;
    int* a;
    int i;
    int N;
    scanf("%d", &N);
    T = buildTree(N);
    flag = 1;
    a = (int*)malloc(N*sizeof(int));
    levelTraversal(T, a, &flag, N);
    printf("%d", a[0]);
    for(i = 1;i < N;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");
    if(flag)
    {
        printf("YES");
    }
    
    else
    {
        printf("NO");
    }
    return 0;
}
int Height(avlTree T)
{
    if(T == NULL)
    {
        return -1;
    }
    return T->height;
}
avlTree LL(avlTree k)
{
    avlTree k1;
    k1 = k->left;
    k->left = k1->right;
    k1->right = k;
    k->height = max(Height(k->left), Height(k->right)) + 1;
    k1->height = max(k->height, Height(k1->left)) + 1;
    return k1;
}
avlTree LR(avlTree k)
{
    k->left = RR(k->left);
    return LL(k);
}
avlTree RL(avlTree k)
{
    k->right = LL(k->right);
    return RR(k);
}
avlTree RR(avlTree k)
{
    avlTree k1;
    k1 = k->right;
    k->right = k1->left;
    k1->left = k;
    k->height = max(Height(k->left), Height(k->right)) + 1;
    k1->height = max(k->height, Height(k1->right)) + 1;
    return k1;
}
avlTree insert(avlTree T, int val)
{
    if(T == NULL)
    {
        T = (avlTree)malloc(sizeof(struct avlNode));
        T->left = T->right = NULL;
        T->height = 0;
        T->val = val;
    }
    else
    {
        if(val < T->val)
        {
            T->left = insert(T->left, val);
            if(Height(T->left) - Height(T->right) == 2)
            {
                if(val < T->left->val)
                {
                    T = LL(T);
                }
                else
                {
                    T = LR(T);
                }
            }
        }
        else if(val > T->val)
        {
            T->right = insert(T->right, val);
            if(Height(T->right) - Height(T->left) == 2)
            {
                if(val < T->right->val)
                {
                    T = RL(T);
                }
                else
                {
                    T = RR(T);
                }
            }
        }
    }
    T->height = max(Height(T->left), Height(T->right)) + 1;
    return T;
    
}
avlTree buildTree(int N)
{
    avlTree T;
    int val;
    int i;
    T = NULL;
    for(i = 0;i < N;i++)
    {
        scanf("%d", &val);
        T = insert(T, val);
    }
    return T;
}
void levelTraversal(avlTree T, int* a, int* flag, int N)
{
    avlTree* queue;
    avlTree k;
    int pre;
    int i;
    int front, rear;
    
    queue = (avlTree*)malloc(N*sizeof(avlTree));
    front = 0;
    rear = -1;
    queue[++rear] = T;
    i = 0;
    pre = 2;
    while(rear - front != -1)
    {
        k = queue[front++];
        a[i++] = k->val;
        if(k->height == 1 && k->left == NULL && k->right)
        {
            *flag = 0;
        }
        if(k->height == 1 && *flag != 0)
        {
            if(has2Child(k) && pre != 2)
            {
                *flag = 0;
            }
            if(has1Child(k) && pre != 2)
            {
                *flag = 0;
            }
        }
        pre = 0;
        if(k->left)
        {
            queue[++rear] = k->left;
            pre++;
        }
        if(k->right)
        {
            queue[++rear] = k->right;
            pre++;
        }
    }
}
int has2Child(avlTree T)
{
    if(T->left && T->right)
    {
        return 1;
    }
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int has1Child(avlTree T)
{
    if(T->left == NULL && T->right || T->left && T->right == NULL)
    {
        return 1;
    }
    return 0;
}
