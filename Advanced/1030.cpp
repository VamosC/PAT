#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

void print_path(const vector<int> &p, int s)
{
    if (p[s] == -1)
    {
        cout << s;
    }
    else
    {
        print_path(p, p[s]);
        cout << " " << s;
    }
}

int main()
{
    unordered_map<int, vector<tuple<int, int, int>>> G;
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (auto i = 0; i < m; ++i)
    {
        int a, b, dist, cost;
        cin >> a >> b >> dist >> cost;
        G[a].push_back(make_tuple(b, dist, cost));
        G[b].push_back(make_tuple(a, dist, cost));
    }
    vector<bool> visit(n, false);
    vector<int> dists(n, -1);
    vector<int> cost(n, -1);
    vector<int> pre(n, -1);
    dists[s] = 0;
    cost[s] = 0;
    while (true)
    {
        int index = -1;
        for (auto i = 0; i < n; ++i)
        {
            if (visit[i])
                continue;
            if (dists[i] == -1)
                continue;
            if (index == -1)
            {
                index = i;
            }
            else
            {
                if (dists[i] < dists[index])
                    index = i;
            }
        }
        if (index == -1)
            break;
        if (G.count(index) != 0)
        {
            auto v = G[index];
            for (auto k = 0; k < v.size(); ++k)
            {
                auto [x, y, z] = v[k];
                if (visit[x])
                    continue;
                if (dists[x] == -1)
                {
                    dists[x] = dists[index] + y;
                    pre[x] = index;
                    cost[x] = cost[index] + z;
                }
                else
                {
                    if (dists[index] + y < dists[x])
                    {
                        dists[x] = dists[index] + y;
                        pre[x] = index;
                        cost[x] = cost[index] + z;
                    }
                    else if (dists[index] + y == dists[x])
                    {
                        if (cost[index] + z < cost[x])
                        {
                            cost[x] = cost[index] + z;
                            pre[x] = index;
                        }
                    }
                }
            }
        }
        visit[index] = true;
    }
    print_path(pre, d);
    cout << " " << dists[d] << " " << cost[d] << '\n';
    return 0;
}