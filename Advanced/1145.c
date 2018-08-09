#include<stdio.h>
#include<stdlib.h>
void adjustSize(int* size);
int isPrime(int n);
int hash(int key, int MSize);
void insert(int* hashTable, int key, int hashValue, int MSize);
void search(int* hashTable, int key, int hashValue, int MSize, int* totalTime);
int main()
{
    int MSize, N, M;
    int i;
    int key;
    int totalTime;
    int* hashTable;
    scanf("%d %d %d", &MSize, &N, &M);
    adjustSize(&MSize);
    hashTable = (int*)malloc((MSize)*sizeof(int));
    for(i = 0;i < MSize;i++)
    {
        hashTable[i] = -1;
    }
    
    for(i = 0;i < N;i++)
    {
        scanf("%d", &key);
        insert(hashTable, key, hash(key, MSize), MSize);
    }
    totalTime = 0;
    for(i = 0;i < M;i++)
    {
        scanf("%d", &key);
        search(hashTable, key, hash(key, MSize), MSize, &totalTime);
    }
    printf("%.1f", totalTime*1.0/M);
    return 0;
}

void adjustSize(int* size)
{
    while(!isPrime((*size)))
    {
        (*size)++;
    }
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

void insert(int* hashTable, int key, int hashValue, int MSize)
{
    int i;
    for(i = 0;i < MSize;i++)
    {
        if(hashTable[hash(hashValue + i*i, MSize)] == -1)
        {
            hashTable[hash(hashValue + i*i, MSize)] = key;
            return;
        }
    }
    printf("%d cannot be inserted.\n", key);
}

void search(int* hashTable, int key, int hashValue, int MSize, int* totalTime)
{
    int i;
    for(i = 0;i <= MSize;i++)
    {
        (*totalTime)++;
        if(hashTable[hash(hashValue + i*i, MSize)] == key)
        {
            return;
        }
        if(hashTable[hash(hashValue + i*i, MSize)] == -1)
        {
            return;
        }
    }
}
