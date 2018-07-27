#include<stdio.h>
#include<stdlib.h>

typedef struct polyNode* poly;
struct polyNode
{
    double coef;
    int expo;
    poly next;
};
poly add(poly p1, poly p2);
poly mul(poly p1, poly p2);
poly init(int N);
//void deleteAll(poly p);
// poly sort(poly p);
// poly merge(poly p);
void removeZero(poly p);
int len(poly p);
int main()
{
    int i;
    int N;
    int size;
    poly p1, p2;
    scanf("%d", &N);
    p1 = init(N);
    scanf("%d", &N);
    p2 = init(N);
    p1 = mul(p1, p2);
    removeZero(p1);
    size = len(p1);
    printf("%d ",size);
    p1 = p1->next;
    while(p1 && p1->next)
    {
        printf("%d %.1lf ",p1->expo, p1->coef);
        p1 = p1->next;
    }
    printf("%d %.1lf",p1->expo, p1->coef);
    return 0;
}

poly init(int N)
{
    poly p, cur, newNode;
    int i;
    p = (poly)malloc(sizeof(struct polyNode));
    p->next = NULL;
    cur = p;
    for(i = 0;i < N;i++)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        newNode->next = NULL;
        scanf("%d %lf",&(newNode->expo), &(newNode->coef));
        cur->next = newNode;
        cur = newNode;
    }
    return p;
}

poly add(poly p1, poly p2)
{
    poly p, cur, newNode, oldNode;
    p1 = p1->next;
    p2 = p2->next;
    p = (poly)malloc(sizeof(struct polyNode));
    p->next = NULL;
    cur = p;
    while(p1 && p2)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        newNode->next = NULL;
        if(p1->expo > p2->expo)
        {
            newNode->expo = p1->expo;
            newNode->coef = p1->coef;
            cur->next = newNode;
            cur = newNode;
            oldNode = p1;
            p1 = p1->next;
            free(oldNode);
        }
        else if(p1->expo < p2->expo)
        {
            newNode->expo = p2->expo;
            newNode->coef = p2->coef;
            cur->next = newNode;
            cur = newNode;
            oldNode = p2;
            p2 = p2->next;
            free(oldNode);
        }
        else
        {
            newNode->expo = p1->expo;
            newNode->coef = p1->coef + p2->coef;
            cur->next = newNode;
            cur = newNode;
            oldNode = p1;
            p1 = p1->next;
            free(oldNode);
            oldNode = p2;
            p2 = p2->next;
            free(oldNode);
        }
    }
    while(p1)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        newNode->next = NULL;
        newNode->coef = p1->coef;
        newNode->expo = p1->expo;
        cur->next = newNode;
        cur = newNode;
        oldNode = p1;
        p1 = p1->next;
        free(oldNode);
    }
    while(p2)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        newNode->next = NULL;
        newNode->coef = p2->coef;
        newNode->expo = p2->expo;
        cur->next = newNode;
        cur = newNode;
        oldNode = p2;
        p2 = p2->next;
        free(oldNode);
    }
    return p;
}

poly mul(poly p1, poly p2)
{
    poly p;
    poly tmp, cur, newNode, head;
    tmp = (poly)malloc(sizeof(struct polyNode));
    tmp->next = NULL;
    p = (poly)malloc(sizeof(struct polyNode));
    p->next = NULL;
    p1 = p1->next;
    head = p1;
    p2 = p2->next;
    while(p2)
    {
        cur = tmp;
        p1 = head;
        while(p1)
        {
            newNode = (poly)malloc(sizeof(struct polyNode));
            newNode->next = NULL;
            newNode->expo = p1->expo + p2->expo;
            newNode->coef = p1->coef * p2->coef;
            cur->next = newNode;
            cur = newNode;
            p1 = p1->next;
        }
        p = add(p, tmp);
//        deleteAll(tmp);
        p2 = p2->next;
    }
    return p;
}

//void deleteAll(poly p)
//{
//    poly tmp;
//    p = p->next;
//    while(p)
//    {
//        tmp = p;
//        p = p->next;
//        free(tmp);
//    }
//}

void removeZero(poly p)
{
    poly pre;
    pre = p;
    p = p->next;
    while(p)
    {
        if(p->coef == 0)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            p = p->next;
            pre = pre->next;
        }
    }
}

int len(poly p)
{
    int length = 0;
    p = p->next;
    while(p)
    {
        length++;
        p = p->next;
    }
    return length;
}
