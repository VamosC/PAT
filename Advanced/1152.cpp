#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    if (x == 1)
        return false;
    for (auto i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int l, k;
    cin >> l >> k;
    string x;
    cin >> x;
    int num;
    bool flag = true;
    for (auto i = 0; i + k <= l; i++)
    {
        num = 0;
        for (auto j = 0; j < k; ++j)
        {
            num *= 10;
            num += (x[i + j] - '0');
        }
        if (isPrime(num))
        {
            flag = false;
            cout << setw(k) << setfill('0') << num << '\n';
            break;
        }
    }
    if (flag)
        cout << "404\n";
    return 0;
}