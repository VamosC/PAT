#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (auto x = 2; x < sqrt(n); x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

int main()
{
    int64_t x;
    cin >> x;
    if (is_prime(x))
    {
        cout << 1 << '\n';
        cout << x << '\n';
        return 0;
    }
    int64_t s, len;
    len = 0;
    for (int64_t i = 2; i <= x; i++)
    {
        int64_t tmp = x;
        int64_t tmp_len = 0;
        for (int64_t j = i; j <= tmp; j++)
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
    cout << len << '\n';
    for (int64_t i = 0; i < len; ++i)
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