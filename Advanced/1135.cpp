#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

bool isRBTree(const vector<int> &t, int root, int r, int &len)
{
    if (root > r)
    {
        len = 1;
        return true;
    }
    int i;
    i = root + 1;
    for (i = root + 1; i <= r; ++i)
    {
        if (abs(t[i]) >= abs(t[root]))
            break;
    }
    int l_path, r_path;
    if (!isRBTree(t, root + 1, i - 1, l_path))
        return false;
    if (!isRBTree(t, i, r, r_path))
        return false;
    if (t[root] < 0)
    {
        if (root + 1 <= r)
        {
            if (t[root + 1] < 0)
                return false;
        }
        if (i <= r)
        {
            if (t[i] < 0)
                return false;
        }
        len = l_path;
    }
    else
    {
        len = l_path + 1;
    }
    if (l_path != r_path)
        return false;
    return true;
}

int main()
{
    int k;
    cin >> k;
    for (auto i = 0; i < k; ++i)
    {
        int n;
        cin >> n;
        vector<int> tree;
        for (auto j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            tree.push_back(x);
        }
        int len = 0;
        if (tree[0] < 0)
            cout << "No\n";
        else
        {
            if (isRBTree(tree, 0, n - 1, len))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}