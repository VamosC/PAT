#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int find(vector<int> &p, int u)
{
    int tmp = u;
    while (p[tmp] != -1)
    {
        tmp = p[tmp];
    }
    while (u != tmp)
    {
        int x = p[u];
        p[u] = tmp;
        u = x;
    }
    return tmp;
}

void unite(vector<int> &p, int u, int v)
{
    p[u] = v;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> djSet(n + 1, -1);
    int odd = 0;
    for (auto i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        v[s]++;
        v[t]++;
        auto root_s = find(djSet, s);
        auto root_t = find(djSet, t);
        if (root_s != root_t)
        {
            unite(djSet, root_s, root_t);
        }
    }
    for (auto i = 1; i < n + 1; ++i)
    {
        if (i == 1)
        {
            cout << v[i];
        }
        else
        {
            cout << " " << v[i];
        }
        if (v[i] % 2 == 1)
            odd++;
    }
    cout << '\n';
    bool is_connect = true;
    int num = 0;
    for (auto i = 1; i < djSet.size(); ++i)
    {
        if (num > 1)
        {
            is_connect = false;
            break;
        }
        if (djSet[i] == -1)
        {
            num++;
        }
    }
    if (!is_connect)
    {
        cout << "Non-Eulerian" << '\n';
    }
    else
    {
        if (odd == 0)
        {
            cout << "Eulerian" << '\n';
        }
        else if (odd == 2)
        {
            cout << "Semi-Eulerian" << '\n';
        }
        else
        {
            cout << "Non-Eulerian" << '\n';
        }
    }
    return 0;
}