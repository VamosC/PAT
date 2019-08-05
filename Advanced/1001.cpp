// for OJ use this
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void int2str(int n, string &s, bool flag)
{
    static unordered_map<int, string> table = {
        {0, "0"},
        {1, "1"},
        {2, "2"},
        {3, "3"},
        {4, "4"},
        {5, "5"},
        {6, "6"},
        {7, "7"},
        {8, "8"},
        {9, "9"}};
    auto count = 0;
    do
    {
        count++;
        s.insert(0, table[n % 10]);
        n /= 10;
    } while (n > 0);
    if (flag)
    {
        for (auto i = 3 - count; i > 0; i--)
        {
            s.insert(0, table[0]);
        }
    }
}

void printFormat(int n)
{
    bool sign = false;
    string res;
    if (n < 0)
    {
        sign = true;
        n = -n;
    }
    do
    {
        if (n / 1000 == 0)
            int2str(n % 1000, res, false);
        else
        {
            int2str(n % 1000, res, true);
            res.insert(0, ",");
        }
        n /= 1000;
    } while (n > 0);
    if (sign)
        res.insert(0, "-");
    cout << res << '\n';
}

int main()
{
    int a, b;
    cin >> a >> b;
    printFormat(a + b);
    return 0;
}