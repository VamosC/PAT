#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int find(const vector<int> &p, const vector<int> &q, int l, int r, int root)
{
    if (l == r)
        return q[l];
    int index = 0;
    for (auto i = l; i <= r; ++i)
    {
        if (q[i] == p[root])
        {
            index = i;
            break;
        }
    }
    if (index != l)
    {
        return find(p, q, l, index - 1, root + 1);
    }
    else
    {
        return find(p, q, index + 1, r, root + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre;
    vector<int> in;
    for (auto i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        pre.push_back(x);
    }
    for (auto i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        in.push_back(x);
    }
    cout << find(pre, in, 0, n - 1, 0) << '\n';
    return 0;
}