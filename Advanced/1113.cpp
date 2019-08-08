#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int sum = 0;
    for (auto i = 0; i < n; ++i)
    {
        if (i < n / 2)
            sum -= v[i];
        else
            sum += v[i];
    }
    cout << n % 2 << ' ' << sum;
    return 0;
}