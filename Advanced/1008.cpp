// For OJ use this
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto seconds = 0;
    auto pos = 0;
    vector<int> v(n);
    for (auto i = 0; i < n; i++)
        cin >> v[i];
    for (auto i = 0; i < n; i++)
    {
        seconds += pos < v[i] ? 6 * (v[i] - pos) + 5 : 4 * (pos - v[i]) + 5;
        pos = v[i];
    }
    cout << seconds;
    return 0;
}