#include <bits/stdc++.h>
using namespace std;

auto static _f = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int n, m;
    int *v;
    cin >> n;
    v = new int[n];
    int x;
    int i;
    for (i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    cin >> m;
    int size = (n + m) % 2 == 0 ? (n + m) / 2 : (n + m + 1) / 2;
    int pos = 0;
    int res = 0;
    for (i = 0; i < m; ++i)
    {
        cin >> x;
        if (pos >= n)
        {
            size--;
            if (size == 0)
            {
                res = x;
                break;
            }
            continue;
        }
        int j;
        for (j = pos; j < n; ++j)
        {
            if (v[j] > x)
            {
                break;
            }
            size--;
            if (size == 0)
            {
                res = v[j];
                break;
            }
        }
        if (size == 0)
            break;
        pos = j;
        size--;
        if (size == 0)
        {
            res = x;
            break;
        }
    }
    if (size != 0)
    {
        res = v[pos + size - 1];
    }
    cout << res << '\n';
    delete[] v;
    return 0;
}