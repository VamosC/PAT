#include <bits/stdc++.h>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    for (auto k = 0; k < a.size(); ++k)
    {
        if (a[k] != b[k])
            return false;
    }
    return true;
}

bool insertSort(vector<int> &a, const vector<int> &b)
{
    auto flag = false;
    for (auto i = 1; i < a.size(); ++i)
    {
        if (compare(a, b))
        {
            flag = true;
        }
        for (auto j = i; j >= 1; --j)
        {
            if (a[j] < a[j - 1])
            {
                auto tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
        if (flag)
            break;
    }
    return flag;
}

bool finish = false;

bool mergeSort(vector<int> &a, const vector<int> &b)
{
    for (auto i = 1; i < a.size(); i *= 2)
    {
        
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> r(n);
    for (auto i = 0; i < n; ++i)
        cin >> a[i];
    for (auto i = 0; i < n; ++i)
        cin >> r[i];
    vector<int> b(a);

    return 0;
}