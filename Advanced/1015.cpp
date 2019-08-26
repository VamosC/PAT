#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    auto static flag = true;
    static char visit[100000];
    if (flag)
    {
        memset(visit, 1, sizeof(char) * 100000);
        visit[1] = 0;
        for (auto i = 2; i < 100000; ++i)
        {
            if (visit[i] == 0)
                continue;
            for (auto j = 2; i * j < 100000; ++j)
            {
                visit[i * j] = 0;
            }
        }
        flag = false;
    }
    return visit[n] == 1;
}

int reverse(int x, int d)
{
    int r = 0;
    while (x > 0)
    {
        r *= d;
        r += x % d;
        x /= d;
    }
    return r;
}

int main()
{
    int x;
    while (cin >> x)
    {
        if (x < 0)
        {
            break;
        }
        int d;
        cin >> d;
        if (is_prime(x) && is_prime(reverse(x, d)))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}