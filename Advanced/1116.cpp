#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    auto static flag = true;
    static char visit[10000];
    if (flag)
    {
        memset(visit, 1, sizeof(char) * 10000);
        visit[1] = 0;
        for (auto i = 2; i < 10000; ++i)
        {
            if (visit[i] == 0)
                continue;
            for (auto j = 2; i * j <= 10000; ++j)
            {
                visit[i * j] = 0;
            }
        }
        flag = false;
    }
    return visit[n] == 1;
}

int main()
{
    unordered_map<string, int> rank;
    set<string> record;
    int n;
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        string id;
        cin >> id;
        rank[id] = i + 1;
    }
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        string query;
        cin >> query;
        if (rank.count(query) == 0)
        {
            cout << query << ": "
                 << "Are you kidding?\n";
        }
        else
        {
            if (record.count(query) != 0)
            {
                cout << query << ": "
                     << "Checked\n";
                continue;
            }
            record.insert(query);
            if (rank[query] == 1)
            {
                cout << query << ": "
                     << "Mystery Award\n";
            }
            else
            {
                auto rank_ = rank[query];
                if (is_prime(rank_))
                {
                    cout << query << ": "
                         << "Minion\n";
                }
                else
                {
                    cout << query << ": "
                         << "Chocolate\n";
                }
            }
        }
    }
    return 0;
}