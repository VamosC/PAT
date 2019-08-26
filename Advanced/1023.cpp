// #include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool is_same_perm(const string &x, const string &y)
{
    char bucket[10];
    memset(bucket, 0, sizeof(char) * 10);
    for (auto it : x)
    {
        bucket[it - '0']++;
    }
    for (auto it : y)
    {
        bucket[it - '0']--;
    }
    for (auto i = 0; i < 10; ++i)
    {
        if (bucket[i] != 0)
            return false;
    }
    return true;
}

string double_n(const string &n)
{
    string x;
    char c = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++)
    {
        if (*it < '5')
        {
            x.insert(x.begin(), '0' + (2 * (*it - '0') + c));
            c = 0;
        }
        else
        {
            x.insert(x.begin(), 2 * (*it - '0') % 10 + '0' + c);
            c = 1;
        }
    }
    if (c == 1)
        x.insert(x.begin(), '1');
    return x;
}

int main()
{
    string n;
    cin >> n;
    auto m = double_n(n);
    if (is_same_perm(n, m))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    cout << m << '\n';
    return 0;
}