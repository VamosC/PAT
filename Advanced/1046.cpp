#include <bits/stdc++.h>
using namespace std;

auto static speed_up = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> v(n);
    int total = 0;
    for (auto i = 0; i < n; ++i)
    {
        cin >> v[i];
        total += v[i];
        if (i == 0)
        {
            r[i] = v[i];
        }
        else
        {
            r[i] = v[i] + r[i - 1];
        }
    }
    int m;
    cin >> m;
    for (auto i = 0; i < m; ++i)
    {
        int s, t;
        cin >> s >> t;
        if (s > t)
        {
            auto tmp = t;
            t = s;
            s = tmp;
        }
        int d1;
        if (s == 1)
        {
            d1 = r[t - 2];
        }
        else
        {
            d1 = r[t - 2] - r[s - 2];
        }
        cout << min(d1, total - d1) << '\n';
    }
    return 0;
}