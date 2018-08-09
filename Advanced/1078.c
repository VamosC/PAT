#include<stdio.h>
#include<stdlib.h>

int isPrime(int n);
int hash(int key, int MSize);
void adjustSize(int* size);
void insert(int key, int hashValue, int* hashTable, int MSize, int* pos);
int main()
{
    int MSize, N;
    int i;
    int key;
    int* hashTable;
    int* pos;
    scanf("%d %d", &MSize, &N);
    adjustSize(&MSize);
    hashTable = (int*)malloc(MSize*sizeof(int));
    pos = (int*)malloc(N*sizeof(int));
    for(i = 0;i < MSize;i++)
    {
        hashTable[i] = -1;
    }
    for(i = 0;i < N;i++)
    {
        scanf("%d", &key);
        pos[i] = -1;
        insert(key, hash(key, MSize), hashTable, MSize, &pos[i]);
    }

    if(pos[0] != -1)
    {
        printf("%d", pos[0]);
    }
    else
    {
        printf("-", pos[0]);
    }

    for(i = 1;i < N;i++)
    {
        if(pos[i] != -1)
        {
            printf(" %d", pos[i]);
        }
        
        else
        {
            printf(" -");
        }
        
    }
    return 0;
}

int isPrime(int n)
{
    int i, j;
    int a[n+1];
    for(i = 0;i <= n;i++)
    {
        a[i] = 1;
    }
    a[1] = 0;
    for(i = 2;i < n;i++)
    {
        if(a[i])
        {
            for(j = 2;i*j <= n && j < n;j++)
            {
                a[i*j] = 0;
            }
        }
    }
    return a[n];
}
int hash(int key, int MSize)
{
    return key % MSize;
}
void adjustSize(int* size)
{
    while(!isPrime(*size))
    {
        (*size)++;
    }
}
void insert(int key, int hashValue, int* hashTable, int MSize, int* pos)
{
    int i;
    int index;
    for(i = 0;i < MSize;i++)
    {
        index = hash(hashValue + i*i, MSize);
        if(hashTable[index] == -1)
        {
            hashTable[index] = key;
            *pos = index;
            return;
        }
    }
}