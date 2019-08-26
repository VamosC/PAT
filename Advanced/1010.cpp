// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

uint64_t cal(const string &x, uint64_t d)
{
    uint64_t r = 0;
    for (auto it : x)
    {
        r *= d;
        if (it >= '0' && it <= '9')
            r += it - '0';
        else if (it >= 'a' && it <= 'z')
            r += it - 'a' + 10;
    }
    return r;
}

int adjust(const string &x)
{
    int d = 2;
    for (auto it : x)
    {
        if (it >= '0' && it <= '9')
        {
            d = max(d, it - '0' + 1);
        }
        else if (it >= 'a' && it <= 'z')
        {
            d = max(d, it - 'a' + 11);
        }
    }
    return d;
}

int main()
{
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 1)
    {
        uint64_t d = adjust(n2);
        auto val_1 = cal(n1, radix);
        auto flag = true;
        while (true)
        {
            if (val_1 < cal(n2, d))
            {
                flag = false;
                break;
            }
            else if (val_1 == cal(n2, d))
            {
                break;
            }
            else if (n2.size() == 1)
            {
                flag = false;
                break;
            }
            else
            {
                d++;
            }
        }
        if (flag)
        {
            cout << d << '\n';
        }
        else
        {
            cout << "Impossible\n";
        }
    }
    else
    {
        uint64_t d = adjust(n1);
        auto val_2 = cal(n2, radix);
        auto flag = true;
        while (true)
        {
            if (val_2 < cal(n1, d))
            {
                flag = false;
                break;
            }
            else if (val_2 == cal(n1, d))
            {
                break;
            }
            else if (n1.size() == 1)
            {
                flag = false;
                break;
            }
            else
            {
                d++;
            }
        }
        if (flag)
        {
            cout << d << '\n';
        }
        else
        {
            cout << "Impossible\n";
        }
    }
    return 0;
}