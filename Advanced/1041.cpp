#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> v;
    for (auto i = 0; i < n; ++i)
        cin >> a[i];

    for (auto i = 0; i < n; ++i)
    {
        if (v.count(a[i]) == 0)
        {
            v[a[i]] = 1;
        }
        else
        {
            v[a[i]]++;
        }
    }
    int i;
    for (i = 0; i < n; ++i)
    {
        if (v[a[i]] == 1)
            break;
    }
    if (i >= n)
        cout << "None\n";
    else
        cout << a[i] << '\n';
    return 0;
}