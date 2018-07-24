#include<stdio.h>
#define MAX 101

void formatPrint(int n);
int sumDigit(char* s);
int main()
{
    char s[MAX];
    int n;
    scanf("%s", s);
    n = sumDigit(s);
    if(n == 0)
    {
        printf("zero");
    }
    
    else
    {
        formatPrint(n);
    }
    
    return 0;
}

int sumDigit(char* s)
{
    int i = 0;
    int sum = 0;
    while(s[i] != '\0')
    {
        sum += s[i] - '0';
        i++;
    }
    return sum;
}

void formatPrint(int n)
{
    char* s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(n/10 == 0)
    {
        if(n != 0)
        {
            printf("%s",s[n%10]);
        }
        return;
    }
    formatPrint(n/10);
    printf(" %s",s[n%10]);
    
}
