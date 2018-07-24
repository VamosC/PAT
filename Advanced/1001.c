#include<stdio.h>

void formatPrint(int n);
int main()
{
    int a, b;
    int sum;
    scanf("%d %d", &a, &b);
    sum = a + b;
    if(sum < 0)
    {
        printf("-");
        sum = -sum;
    }
    formatPrint(sum);
    return 0;
}

void formatPrint(int n)
{
    if(n/1000 == 0)
    {
        printf("%d",n%1000);
        return;
    }
    formatPrint(n/1000);
    n = n%1000;
    printf(",");
    printf("%d",n/100);
    printf("%d",n%100/10);
    printf("%d",n%100%10);
}
