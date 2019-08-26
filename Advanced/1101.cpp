#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto i = 0; i < n; ++i)
        cin >> v[i];
    vector<int> r;
    vector<int> max_(n);
    vector<int> min_(n);
    max_[0] = -1;
    min_[n - 1] = 0x3f3f3f3f;
    for (auto i = 1; i < n; ++i)
    {
        max_[i] = max(max_[i - 1], v[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        min_[i] = min(min_[i + 1], v[i + 1]);
    }
    for (auto i = 0; i < n; ++i)
    {
        if (v[i] < max_[i])
            continue;
        if (v[i] > min_[i])
            continue;
        r.push_back(v[i]);
    }
    cout << r.size() << '\n';
    sort(r.begin(), r.end());
    for (auto i = 0; i < r.size(); ++i)
    {
        if (i == 0)
        {
            cout << r[i];
        }
        else
        {
            cout << " " << r[i];
        }
    }
    cout << '\n';
    return 0;
}