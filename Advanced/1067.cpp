// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> v(n, false);
    for (auto i = 0; i < n; ++i)
        cin >> a[i];
    int count = 0;
    int last = 0;
    while (true)
    {
        int index = 0;
        int i = 0;
        for (i = last; i < n; ++i)
        {
            if (v[i])
            {
                continue;
            }
            else
            {
                if (i == a[i])
                {
                    v[i] = true;
                    continue;
                }
                else
                {
                    index = i;
                    break;
                }
            }
        }
        if (i >= n)
            break;
        last = index;
        bool zero = false;
        while (!v[index])
        {
            if (a[index] == 0)
                zero = true;
            count++;
            v[index] = true;
            index = a[index];
        }
        if (zero)
        {
            count--;
        }
        else
        {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}