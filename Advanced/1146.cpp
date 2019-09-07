#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

bool is_topological(vector<vector<int>> v, const vector<int> &seq)
{
    vector<int> degree(v.size(), 0);
    for (auto i = 1; i < v.size(); ++i)
    {
        auto e = v[i];
        for (auto it : e)
        {
            degree[it]++;
        }
    }
    for (auto val : seq)
    {
        if (degree[val] != 0)
        {
            return false;
        }
        for (auto it : v[val])
            degree[it]--;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (auto i = 0; i < m; ++i)
    {
        int s, t;
        cin >> s >> t;
        v[s].push_back(t);
    }
    int k;
    cin >> k;
    vector<int> p;
    bool flag = true;
    for (auto i = 0; i < k; ++i)
    {
        p.clear();
        for (auto j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            p.push_back(x);
        }
        if (!is_topological(v, p))
        {
            if (flag)
            {
                cout << i;
                flag = false;
            }
            else
                cout << " " << i;
        }
    }
    return 0;
}