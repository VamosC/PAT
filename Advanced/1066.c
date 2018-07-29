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
int max(int a, int b);
avlTree insert(avlTree T, int val);
avlTree buildTree(int N);
avlTree LL(avlTree k);
avlTree LR(avlTree k);
avlTree RL(avlTree k);
avlTree RR(avlTree k);

int main()
{
    int N;
    avlTree T;
    scanf("%d", &N);
    T = buildTree(N);
    printf("%d", T->val);
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

int max(int a, int b)
{
    return a > b ? a : b;
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
    int i;
    int val;
    avlTree T;
    T = NULL;
    for(i = 0;i < N;i++)
    {
        scanf("%d", &val);
        T = insert(T, val);
    }
    return T;
}

avlTree LL(avlTree k)
{
    avlTree k1;
    k1 = k->left;
    k->left = k1->right;
    k1->right = k;
    k->height = max(Height(k->left), Height(k->right)) + 1;
    k1->height = max(k->height, Height(k->left)) + 1;
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
    k1->height = max(k->height, Height(k->right)) + 1;
    return k1;
}