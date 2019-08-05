// For OJ use this
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> v(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min_ = 0, max_ = n - 1;
    int64_t sum = 0;
    int64_t maxSum = -1;
    int pos_ = 0;
    int start = 0;
    for (auto &digit : v)
    {
        sum += digit;
        if (sum < 0)
        {
            start = pos_ + 1;
            sum = 0;
        }
        else
        {
            if (sum > maxSum)
            {
                min_ = start;
                max_ = pos_;
                maxSum = sum;
            }
        }
        pos_++;
    }
    if (maxSum < 0)
        maxSum = 0;
    cout << maxSum << " " << v[min_] << " " << v[max_];
    return 0;
}