#include<stdio.h>
#include<string.h>

#define MAX 15
int findRadix(char* N1, char* N2, int tag, int radix);
unsigned long long calNum(char* N, int radix);
int num(char c);
int radixDecide(char* N);
int binarySearch(unsigned long long cmp, char* N, long long  l, long long r);
int max(int a, int b);
int main()
{
    char N1[MAX];
    char N2[MAX];
    int res;
    int radix, tag;
    scanf("%s %s %d %d",N1, N2, &tag, &radix);
    res = findRadix(N1, N2, tag, radix);
    if(res == -1)
    {
        printf("Impossible");
    }
    
    else
    {
        printf("%d", res);
    }
    return 0;
}

int findRadix(char* N1, char* N2, int tag, int radix)
{
    unsigned long long realNum = 0;
    int i;
    if(tag == 2)
    {
        return findRadix(N2, N1, 1, radix);
    }
    if(strcmp(N1, N2) == 0)
    {
        return radix;
    }
    realNum = calNum(N1, radix);
    i = radixDecide(N2);
    return binarySearch(realNum, N2, i, realNum+1);
}

unsigned long long calNum(char* N, int radix)
{
    int i;
    unsigned long long res;
    i = 0;
    res = 0;
    while(N[i] != '\0')
    {
        res *= radix;
        res += num(N[i]);
        i++;
    }
    return res;
}

int num(char c)
{
    if(c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else
    {
        return c - 'a' + 10;
    }
}


int radixDecide(char* N)
{
    int radix = 0;
    int i;
    i = 0;
    while(N[i] != '\0')
    {
        if(radix < num(N[i]))
        {
            radix = num(N[i]);
        }
        i++;
    }
    return radix + 1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int binarySearch(unsigned long long cmp, char* N, long long l, long long r)
{
    int mid;
    unsigned long long res;
    while(l <= r)
    {
        mid = (l+r)/2;
        res = calNum(N, mid);
        if(res < cmp)
        {
            l = mid + 1;
        }
        else if(res > cmp)
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
