#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<uint32_t> matrix;
    int n, m;
    cin >> m >> n;
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
        {
            uint32_t x;
            cin >> x;
            matrix.push_back(x);
        }
    }
    int i, j;
    i = j = 0;
    while (true)
    {
        while (i < matrix.size() && matrix[i] == matrix[j])
            i++;
        if (i >= matrix.size())
            break;
        if (2 * (i - j) >= matrix.size())
            break;
        j = i;
    }
    cout << matrix[j];
    return 0;
}