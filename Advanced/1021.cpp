#include <bits/stdc++.h>
using namespace std;

struct Set
{
    vector<int> s;
    Set(int n)
    {
        for (auto i = 0; i <= n; ++i)
            s.push_back(i);
    }
    int find(int x)
    {
        auto root = x;
        while (root != s[root])
            root = s[root];
        while (x != root)
        {
            auto tmp = s[x];
            s[x] = root;
            x = tmp;
        }
        return root;
    }
    void unite(int x, int y)
    {
        s[x] = y;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    int isTree()
    {
        int count = 0;
        for (auto i = 1; i < s.size(); ++i)
        {
            if (s[i] == i)
                count++;
        }
        return count;
    }
};

int dfs(vector<vector<int>> &g, int i, int pre)
{
    if (g[i].size() == 1 && pre != 0)
    {
        return 1;
    }
    auto &v = g[i];
    int max = -1;
    for (auto e : v)
    {
        if (e != pre)
        {
            auto d = dfs(g, e, i);
            if (max < d)
            {
                max = d;
            }
        }
    }
    return max + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (auto i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> r;
    Set s(n);
    for (auto i = 1; i < g.size(); ++i)
    {
        auto v = g[i];
        for (auto e : v)
        {
            if (!s.same(i, e))
                s.unite(s.find(i), s.find(e));
        }
    }
    auto part = s.isTree();
    if (part != 1)
    {
        cout << "Error: " << part << " components" << '\n';
    }
    else
    {
        int deepest = -1;
        for (auto i = 1; i <= n; ++i)
        {
            auto depth = dfs(g, i, 0);
            if (depth > deepest)
            {
                r.clear();
                r.push_back(i);
                deepest = depth;
            }
            else if (depth == deepest)
            {
                r.push_back(i);
            }
        }
        sort(r.begin(), r.end());
        for (auto it : r)
        {
            cout << it << '\n';
        }
    }

    return 0;
}