#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int k;
    cin >> k;
    vector<int> v;
    for (auto i = 0; i < k; ++i)
    {
        bool flag = true;
        v.clear();
        int n;
        int x;
        cin >> n;
        set<int> s;
        for (auto j = 0; j < n; ++j)
        {
            cin >> x;
            if (!flag)
                continue;
            if (s.count(x) != 0)
            {
                flag = false;
                continue;
            }
            s.insert(x);
            for (auto m = 0; m < v.size(); ++m)
            {
                if (j - m == x - v[m])
                {
                    flag = false;
                    break;
                }
            }
            v.push_back(x);
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}