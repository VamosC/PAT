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
    int num = 1;
    for (auto el : v)
    {
        if (el <= 0)
            continue;
        if (el == num)
            num++;
        else if (el < num)
            continue;
        else
            break;
    }
    cout << num;
}