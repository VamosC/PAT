#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int s, len;
    len = 0;
    for (auto i = 2; i <= sqrt(x); i++)
    {
        auto tmp = x;
        auto tmp_len = 0;
        for (auto j = i; j <= tmp; j++)
        {
            if (tmp % j == 0)
            {
                tmp /= j;
                tmp_len++;
            }
            else
                break;
        }
        if (tmp_len > len)
        {
            len = tmp_len;
            s = i;
        }
    }
    if (len == 0)
    {
        cout << 1 << '\n'
             << x << '\n';
        return 0;
    }
    cout << len << '\n';
    for (auto i = 0; i < len; ++i)
    {
        if (i == 0)
        {
            cout << s;
        }
        else
        {
            cout << "*" << s;
        }
        s++;
    }
    return 0;
}