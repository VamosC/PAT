#include <bits/stdc++.h>

using namespace std;

void parse_friend(set<int> &s, int n)
{
    int sum = 0;
    do
    {
        sum += n % 10;
        n /= 10;
    } while (n > 0);
    if (s.count(sum) == 0)
    {
        s.insert(sum);
    }
}

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for (auto i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        parse_friend(s, x);
    }
    cout << s.size() << '\n';
    int size = s.size();
    for (auto el : s)
    {
        if (size != 1)
            cout << el << ' ';
        else
            cout << el;
        size--;
    }
}