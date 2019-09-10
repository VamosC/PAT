#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n, -1);
    vector<vector<int>> G(n);
    for (auto i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    int k;
    cin >> k;
    for (auto i = 0; i < k; ++i)
    {
        vector<int> c;
        set<int> s;
        bool flag = true;
        for (auto j = 0; j < n; ++j)
        {
            int color;
            cin >> color;
            c.push_back(color);
        }
        for (auto j = 0; j < n; ++j)
        {
            if (s.count(c[j]) == 0)
                s.insert(c[j]);
            for (auto e : G[j])
            {
                if (c[e] == c[j])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (!flag)
            cout << "No\n";
        else
            cout << s.size() << "-coloring\n";
    }
    return 0;
}