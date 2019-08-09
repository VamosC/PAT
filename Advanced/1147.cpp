#include <bits/stdc++.h>

using namespace std;

void post_order(const vector<int> &heap, int i)
{
    if (i < heap.size())
    {
        post_order(heap, 2 * i + 1);
        post_order(heap, 2 * i + 2);
        if (i == 0)
            cout << heap[i];
        else
            cout << heap[i] << ' ';
    }
}

bool is_max_heap(const vector<int> &heap)
{
    bool flag = true;
    for (auto i = 0; i < heap.size(); ++i)
    {
        if (2 * i + 1 < heap.size())
        {
            if (heap[2 * i + 1] > heap[i])
            {
                flag = false;
                break;
            }
        }
        if (2 * i + 2 < heap.size())
        {
            if (heap[2 * i + 2] > heap[i])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

bool is_min_heap(const vector<int> &heap)
{
    bool flag = true;
    for (auto i = 0; i < heap.size(); ++i)
    {
        if (2 * i + 1 < heap.size())
        {
            if (heap[2 * i + 1] < heap[i])
            {
                flag = false;
                break;
            }
        }
        if (2 * i + 2 < heap.size())
        {
            if (heap[2 * i + 2] < heap[i])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (auto i = 0; i < m; ++i)
    {
        vector<int> heap(n);
        for (auto j = 0; j < n; ++j)
            cin >> heap[j];
        if (is_max_heap(heap))
        {
            cout << "Max Heap\n";
        }
        else if (is_min_heap(heap))
        {
            cout << "Min Heap\n";
        }
        else
        {
            cout << "Not Heap\n";
        }
        post_order(heap, 0);
        cout << '\n';
    }
    return 0;
}