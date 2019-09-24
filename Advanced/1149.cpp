#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int N, M;
    cin >> N >> M;
    unordered_map<int, set<int>> incompatible;
    for (auto i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        incompatible[x].insert(y);
        incompatible[y].insert(x);
    }
    for (auto i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        vector<int> v(num);
        for (auto j = 0; j < num; j++)
        {
            cin >> v[j];
        }
        bool flag = true;
        for (auto j = 0; j < num; j++)
        {
            if (incompatible.count(v[j]) == 0)
                continue;
            for (auto k = j + 1; k < num; k++)
            {
                if (incompatible[v[j]].count(v[k]) != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}