#include <bits/stdc++.h>
using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    string s;
    cin >> s;
    int n1 = (s.size() + 2) / 3;
    int n2 = s.size() + 2 - 2 * n1;
    auto rit = s.end();
    rit--;
    auto it = s.begin();
    while (n1 != 1)
    {
        cout << *it;
        for (auto i = 0; i < n2 - 2; i++)
        {
            cout << " ";
        }
        cout << *rit << '\n';
        it++;
        rit--;
        n1--;
    }
    while (true)
    {
        cout << *it;
        it++;
        if (it == rit)
        {
            cout << *it;
            break;
        }
    }
    return 0;
}