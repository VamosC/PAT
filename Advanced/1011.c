#include<stdio.h>

int main()
{
    char s[3] = {'W', 'T', 'L'};
    int i, j;
    int index;
    double odd;
    double profit;
    double maxOdd;
    profit = 1;
    for(i = 0;i < 3;i++)
    {
        index = 0;
        maxOdd = 0;
        for(j = 0;j < 3;j++)
        {
            scanf("%lf",&odd);
            if(odd > maxOdd)
            {
                maxOdd = odd;
                index = j;
            }
        }
        profit *= maxOdd;
        printf("%c ",s[index]);
    }
    profit = (profit*0.65-1)*2;
    printf("%.2lf",profit);
    return 0;
}
