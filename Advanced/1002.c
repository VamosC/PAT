#include<stdio.h>
#include<stdlib.h>

typedef struct polyNode* poly;
struct polyNode
{
    double coef;
    int expo;
    poly next;
};
int count = 0;
poly initialize(int n);
poly add(poly p1, poly p2);
void delZero(poly p);
void list(poly p);

int main()
{
    poly p1, p2;
    int n;
    scanf("%d",&n);
    p1 = initialize(n);
    scanf("%d",&n);
    p2 = initialize(n);
    p1 = add(p1, p2);
    delZero(p1);
    list(p1);
}

poly initialize(int n)
{
    int i;
    poly p, temp, newNode;
    p = (poly)malloc(sizeof(struct polyNode));
    p->next = NULL;
    temp = p;
    for(i = 0;i < n;i++)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        scanf("%d %lf", &(newNode->expo), &(newNode->coef));
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode;
    }
    return p;
}

poly add(poly p1, poly p2)
{
    poly p3, newNode, temp, oldNode;
    p3 = (poly)malloc(sizeof(struct polyNode));
    p3->next = NULL;
    p1 = p1->next;
    p2 = p2->next;
    temp = p3;
    while(p1 && p2)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        if(p1->expo > p2->expo)
        {
            oldNode = p1;
            newNode->coef = p1->coef;
            newNode->expo = p1->expo;
            p1 = p1->next;
            free(oldNode);
        }
        else if(p2->expo > p1->expo)
        {
            oldNode = p2;
            newNode->coef = p2->coef;
            newNode->expo = p2->expo;
            p2 = p2->next;
            free(oldNode);
        }
        else
        {
            newNode->coef = p1->coef + p2->coef;
            newNode->expo = p1->expo;
            oldNode = p1;
            p1 = p1->next;
            free(oldNode);
            oldNode = p2;
            p2 = p2->next;
            free(oldNode);
        }
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode;
        count++;
    }
    while(p1)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        newNode->coef = p1->coef;
        newNode->expo = p1->expo;
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode;
        oldNode = p1;
        p1 = p1->next;
        free(oldNode);
        count++;
    }
    while(p2)
    {
        newNode = (poly)malloc(sizeof(struct polyNode));
        newNode->coef = p2->coef;
        newNode->expo = p2->expo;
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode;
        oldNode = p2;
        p2 = p2->next;
        free(oldNode);
        count++;
    }
    return p3;
}

void delZero(poly p)
{
    poly temp;
    temp = p;
    p = p->next;
    while(p)
    {
        if(p->coef == 0)
        {
            temp->next = p->next;
            p->next = NULL;
            free(p);
            p = temp->next;
            count--;
        }
        else
        {
            p = p->next;
            temp = temp->next;
        }
    }
}

void list(poly p)
{
    p = p->next;
    if(count == 0)
    {
        printf("0");
        return;
    }
    printf("%d ", count);
    while(p && p->next)
    {
        printf("%d ", p->expo);
        printf("%.1lf ", p->coef);
        p = p->next;
    }
    printf("%d ", p->expo);
    printf("%.1lf", p->coef);
}
