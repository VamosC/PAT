#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (auto i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int findSmallestPrime(int x)
{
    while (true)
    {
        if (isPrime(x))
            break;
        x++;
    }
    return x;
}

int main()
{
    int MSize, N, M;
    cin >> MSize >> N >> M;
    vector<int> v(findSmallestPrime(MSize), 0x3f3f3f3f);
    vector<int> res;
    for (auto i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        int index = x;
        bool flag = false;
        for (auto j = 0; j < v.size(); ++j)
        {
            if (v[index % v.size()] == 0x3f3f3f3f)
            {
                v[index % v.size()] = x;
                flag = true;
                break;
            }
            index += (2 * j + 1);
        }
        if (!flag)
        {
            res.push_back(x);
        }
    }
    int times = 0;
    for (auto i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        int index = x;
        for (auto j = 0; j <= v.size(); ++j)
        {
            times++;
            if (v[index % v.size()] == 0x3f3f3f3f)
            {
                break;
            }
            if (v[index % v.size()] == x)
            {
                break;
            }
            index += (2 * j + 1);
        }
    }
    double average_times = (times * 1.0) / M;
    for (auto x : res)
    {
        cout << x << " cannot be inserted.\n";
    }
    printf("%.1lf\n", average_times);
    return 0;
}