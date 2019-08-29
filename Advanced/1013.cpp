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
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    int findNum(int t)
    {
        int count = 0;
        for (auto i = 1; i < s.size(); ++i)
        {
            if (i == t)
                continue;
            if (i == s[i])
                count++;
        }
        return count;
    }

    int find(int x)
    {
        auto pre = x;
        while (x != s[x])
        {
            x = s[x];
        }
        while (pre != x)
        {
            auto tmp = s[pre];
            s[pre] = x;
            pre = tmp;
        }
        return x;
    }
    void unite(int x, int y)
    {
        s[x] = y;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n + 1);
    int a, b;
    for (auto i = 0; i < m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int t;
    for (auto i = 0; i < k; ++i)
    {
        cin >> t;
        Set s(n);
        for (auto j = 1; j < n + 1; ++j)
        {
            if (j == t)
                continue;
            else
            {
                auto v = graph[j];
                for (auto e : v)
                {
                    if (e == t)
                    {
                        continue;
                    }
                    if (!s.same(e, j))
                        s.unite(s.find(e), s.find(j));
                }
            }
        }
        auto count = s.findNum(t);
        cout << count - 1 << '\n';
    }
}