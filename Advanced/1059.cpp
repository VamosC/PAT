#include <bits/stdc++.h>
using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

bool is_prime(int x)
{
    for (auto i = 2; i < sqrt(x); ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> t;
    if (n == 1)
    {
        cout << "1=1\n";
        return 0;
    }
    int index = 2;
    cout << n << "=";
    while (n != 1)
    {
        for (auto i = index; i <= n; ++i)
        {
            if (!is_prime(i))
                continue;
            if (n % i == 0)
            {
                n /= i;
                index = i;
                t[i]++;
                break;
            }
        }
    }
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        cout << it->first;
        if (it->second != 1)
            cout << "^" << it->second;
        if (++it == t.end())
        {
            break;
        }
        --it;
        cout << "*";
    }
    return 0;
}