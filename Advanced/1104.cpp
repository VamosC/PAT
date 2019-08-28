// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> d(n);
    double sum = 0.0;
    for (auto i = 0; i < n; ++i)
        cin >> d[i];
    for (auto i = 0; i < n; ++i)
    {
        sum += d[i] * (n - i) * (i + 1);
    }
    printf("%.2lf", sum);
    return 0;
}