// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

struct MaxHeap
{
    vector<int> max_heap;
    int heap_size;
    void make_max_heap()
    {
        heap_size = max_heap.size();
        for (int i = (max_heap.size() - 1) / 2; i >= 1; i--)
        {
            per_down(i);
        }
    }
    void per_down(int i)
    {
        auto x = max_heap[i];
        while (2 * i < heap_size)
        {
            if (2 * i + 1 < heap_size && max_heap[2 * i + 1] > max_heap[2 * i])
            {
                if (x < max_heap[2 * i + 1])
                {
                    max_heap[i] = max_heap[2 * i + 1];
                    i = 2 * i + 1;
                }
                else
                    break;
            }
            else
            {
                if (x < max_heap[2 * i])
                {
                    max_heap[i] = max_heap[2 * i];
                    i *= 2;
                }
                else
                    break;
            }
        }
        max_heap[i] = x;
    }
    void sort_one_iter()
    {
        if (heap_size > 1)
        {
            int tmp = max_heap[1];
            max_heap[1] = max_heap[heap_size - 1];
            max_heap[heap_size - 1] = tmp;
            heap_size--;
            per_down(1);
        }
    }
};

struct InsertArray
{
    vector<int> inserted_sort;
    void sort_one_iter()
    {
        static int index = 1;
        if (index < inserted_sort.size())
        {
            auto tmp = inserted_sort[index];
            int i;
            for (i = index; i > 0; i--)
            {
                if (inserted_sort[i - 1] > tmp)
                    inserted_sort[i] = inserted_sort[i - 1];
                else
                    break;
            }
            inserted_sort[i] = tmp;
            index++;
        }
    }
};

bool compare(vector<int> &v1, vector<int> &v2, int m, int n)
{
    for (auto i = m, j = n; i < v1.size() && j < v2.size(); ++i, ++j)
    {
        if (v1[i] != v2[j])
            return false;
    }
    return true;
}

void print_vector(vector<int> &v, int m)
{
    for (auto i = m; i < v.size(); i++)
    {
        if (i == m)
            cout << v[i];
        else
            cout << " " << v[i];
    }
}

int main()
{
    int n;
    cin >> n;
    MaxHeap p;
    InsertArray q;
    p.max_heap.push_back(INT_MAX);
    vector<int> perm_iter(n);
    for (auto i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        p.max_heap.push_back(x);
        q.inserted_sort.push_back(x);
    }
    for (auto i = 0; i < n; ++i)
        cin >> perm_iter[i];
    p.make_max_heap();
    bool tag;
    for (auto i = 0; i < n; ++i)
    {
        q.sort_one_iter();
        if (compare(q.inserted_sort, perm_iter, 0, 0))
        {
            tag = true;
            break;
        }
        p.sort_one_iter();
        if (compare(p.max_heap, perm_iter, 1, 0))
        {
            tag = false;
            break;
        }
    }
    if (tag)
    {
        cout << "Insertion Sort\n";
        q.sort_one_iter();
        print_vector(q.inserted_sort, 0);
    }
    else
    {
        cout << "Heap Sort\n";
        p.sort_one_iter();
        print_vector(p.max_heap, 1);
    }
    return 0;
}