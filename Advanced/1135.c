#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct RBTreeNode* RBTree;
struct RBTreeNode
{
    int val;
    RBTree left;
    RBTree right;
    int color;
    int bh;
};
RBTree buildRBTree(RBTree T, int l, int r, int* a);
int isRBTree(RBTree T);
int bh(RBTree T);
int main()
{
    int N, M;
    int i, j;
    int* a;
    RBTree T;
    scanf("%d", &N);
    for(i = 0;i < N;i++)
    {
        scanf("%d", &M);
        T = NULL;
        a = (int*)malloc(M*sizeof(int));
        for(j = 0;j < M;j++)
        {
            scanf("%d", &a[j]);
        }
        T = buildRBTree(T, 0, M-1, a);
        if(isRBTree(T) && T->color == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}

RBTree buildRBTree(RBTree T, int l, int r, int* a)
{
    int i;
    if(l > r)
    {
        return NULL;
    }
    else
    {
        if(T == NULL)
        {
            T = (RBTree)malloc(sizeof(struct RBTreeNode));
            T->val = a[l];
            T->left = T->right = NULL;
            T->color = T->val > 0 ? 1 : 0;
        }
        for(i = l+1;i <= r;i++)
        {
            if(abs(a[i]) > abs(a[l]))
            {
                break;
            }
        }
        T->left = buildRBTree(T->left, l+1, i-1, a);
        T->right = buildRBTree(T->right, i, r, a);
        return T;
    }
}

int isRBTree(RBTree T)
{
    if(T == NULL)
    {
        return 1;
    }
    if(!isRBTree(T->left) || !isRBTree(T->right))
    {
        return 0;
    }
    if(T->color == 0)
    {
        if(T->left && T->left->color == 0)
        {
            return 0;
        }
        if(T->right && T->right->color == 0)
        {
            return 0;
        }
    }
    if(bh(T->left) != bh(T->right))
    {
        return 0;
    }
    T->bh = T->color == 1 ? bh(T->left) + 1 : bh(T->left);
    return 1;
}

int bh(RBTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    return T->bh;
}
