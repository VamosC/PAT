#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int s0, s1;
    cin >> n >> m >> s0 >> s1;
    unordered_map<int, vector<tuple<int, int64_t>>> roads;
    vector<int> persons(n);
    vector<int> numbers(n, 0);
    vector<int> hands(n, 0);
    vector<bool> visit(n, false);
    vector<int64_t> dists(n, INT64_MAX);
    for (auto i = 0; i < n; ++i)
        cin >> persons[i];
    for (auto i = 0; i < m; ++i)
    {
        int a, b;
        int64_t dist;
        cin >> a >> b >> dist;
        roads[a].push_back(make_tuple(b, dist));
        roads[b].push_back(make_tuple(a, dist));
    }

    bool flag = false;
    dists[s0] = 0;
    hands[s0] = persons[s0];
    numbers[s0] = 1;
    for (auto i = 0; i < n; ++i)
    {
        if (flag)
        {
            break;
        }
        else
        {
            auto min = INT64_MAX;
            int tag = 0;
            for (auto j = 0; j < n; ++j)
            {
                if (!visit[j])
                {
                    if (dists[j] < min)
                    {
                        tag = j;
                        min = dists[j];
                    }
                }
            }
            visit[tag] = true;
            if (tag == s1)
            {
                flag = true;
                continue;
            }
            if (roads.count(tag) == 0)
                continue;
            auto road = roads[tag];
            for (auto k = 0; k < road.size(); ++k)
            {
                auto [x, y] = road[k];
                if (!visit[x])
                {
                    if (y + dists[tag] < dists[x])
                    {
                        dists[x] = y + dists[tag];
                        numbers[x] = numbers[tag];
                        if (hands[x] < hands[tag] + persons[x])
                        {
                            hands[x] = hands[tag] + persons[x];
                        }
                    }
                    else if (y + dists[tag] == dists[x])
                    {
                        numbers[x] += numbers[tag];
                        if (hands[x] < hands[tag] + persons[x])
                        {
                            hands[x] = hands[tag] + persons[x];
                        }
                    }
                }
            }
        }
    }
    cout << numbers[s1] << ' ' << hands[s1];
    return 0;
}