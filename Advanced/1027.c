#include<stdio.h>

void color2Mars(int color);
char convert(int color);
int main()
{
    int a[3];
    int i;
    for(i = 0;i < 3;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("#");
    if(a[0] >= 0 && a[0] < 13)
    {
        printf("%c", '0');
    }
    color2Mars(a[0]);
    if(a[1] >= 0 && a[1] < 13)
    {
        printf("%c", '0');
    }
    color2Mars(a[1]);
    if(a[2] >= 0 && a[2] < 13)
    {
        printf("%c", '0');
    }
    color2Mars(a[2]);
}

void color2Mars(int color)
{
    if(color >= 0 && color < 13)
    {
        printf("%c", convert(color));
        return;
    }
    color2Mars(color/13);
    printf("%c", convert(color%13));
}

char convert(int color)
{
    if(color >= 0 && color <= 9)
    {
        return '0' + color;
    }
    return 'A' + color - 10;
}
