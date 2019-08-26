// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int find_prime(int n)
{
    static char visit[11000];
    auto static flag = true;
    if (flag)
    {
        memset(visit, 1, sizeof(char) * 11000);
        visit[1] = 0;
        for (auto i = 2; i < 11000; ++i)
        {
            if (visit[i] == 0)
                continue;
            for (auto j = 2; i * j <= 11000; ++j)
            {
                visit[i * j] = 0;
            }
        }
        flag = false;
    }
    if (visit[n] == 1)
        return n;
    else
    {
        for (auto i = n + 1; i < 11000; ++i)
        {
            if (visit[i] == 1)
                return i;
        }
        return -1;
    }
}

int hash_f(int x, int m)
{
    return x % m;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for (auto i = 0; i < n; ++i)
        cin >> v[i];
    m = find_prime(m);
    unordered_map<int, int> hash_t;
    set<int> index;
    for (auto it : v)
    {
        auto h = hash_f(it, m);
        if (index.count(h) == 0)
        {
            hash_t[it] = h;
            index.insert(h);
        }
        else
        {
            auto delt = 0;
            for (auto i = 0; i < m; ++i)
            {
                delt += 2 * i + 1;
                auto h = hash_f(it + delt, m);
                if (index.count(h) == 0)
                {
                    hash_t[it] = h;
                    index.insert(h);
                    break;
                }
            }
        }
    }
    for (auto i = 0; i < v.size(); ++i)
    {
        if (hash_t.count(v[i]) != 0)
        {
            if (i == 0)
                cout << hash_t[v[i]];
            else
                cout << " " << hash_t[v[i]];
        }
        else
        {
            if (i == 0)
                cout << "-";
            else
                cout << " -";
        }
    }
    return 0;
}