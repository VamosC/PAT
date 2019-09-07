#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

vector<int> S;

void printPath(vector<vector<int>> &r, const vector<int> &h, int root)
{
    if (2 * root + 1 >= h.size())
    {
        S.push_back(h[root]);
        r.push_back(S);
        S.pop_back();
        return;
    }
    S.push_back(h[root]);
    if (2 * root + 2 < h.size())
        printPath(r, h, 2 * root + 2);
    printPath(r, h, 2 * root + 1);
    S.pop_back();
    return;
}

bool isMaxHeap(const vector<int> &h, int root)
{
    if (2 * root + 1 < h.size())
    {
        if (h[root] >= h[2 * root + 1])
        {
            if (!isMaxHeap(h, 2 * root + 1))
                return false;
        }
        else
            return false;
    }
    if (2 * root + 2 < h.size())
    {
        if (h[root] >= h[2 * root + 2])
        {
            if (!isMaxHeap(h, 2 * root + 2))
                return false;
        }
        else
            return false;
    }
    return true;
}

bool isMinHeap(const vector<int> &h, int root)
{
    if (2 * root + 1 < h.size())
    {
        if (h[root] <= h[2 * root + 1])
        {
            if (!isMinHeap(h, 2 * root + 1))
                return false;
        }
        else
            return false;
    }
    if (2 * root + 2 < h.size())
    {
        if (h[root] <= h[2 * root + 2])
        {
            if (!isMinHeap(h, 2 * root + 2))
                return false;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heap(n);
    for (auto i = 0; i < n; ++i)
        cin >> heap[i];
    vector<vector<int>> res;
    printPath(res, heap, 0);
    for (auto i = 0; i < res.size(); ++i)
    {
        for (auto j = 0; j < res[i].size(); ++j)
        {
            if (j == 0)
                cout << res[i][j];
            else
                cout << " " << res[i][j];
        }
        cout << '\n';
    }
    if (isMaxHeap(heap, 0))
    {
        cout << "Max Heap";
    }
    else if (isMinHeap(heap, 0))
    {
        cout << "Min Heap";
    }
    else
    {
        cout << "Not Heap";
    }
    return 0;
}