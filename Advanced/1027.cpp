#include <bits/stdc++.h>

using namespace std;

string transform(int x)
{
    unordered_map<int, string> table = {
        {0, "0"},
        {1, "1"},
        {2, "2"},
        {3, "3"},
        {4, "4"},
        {5, "5"},
        {6, "6"},
        {7, "7"},
        {8, "8"},
        {9, "9"},
        {10, "A"},
        {11, "B"},
        {12, "C"}};
    string res;
    do
    {
        res.insert(0, table[x % 13]);
        x /= 13;
    } while (x > 0);
    if (res.size() == 1)
        res.insert(0, "0");
    return res;
}

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    string res;
    res.append("#");
    res.append(transform(r));
    res.append(transform(g));
    res.append(transform(b));
    cout << res;
    return 0;
}