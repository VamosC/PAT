// For OJ use this
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> res;
    static unordered_map<int, char> int2char = {
        {0, 'W'},
        {1, 'T'},
        {2, 'L'}};
    double max_profit = 1.0;
    for (auto i = 0; i < 3; i++)
    {
        double max_profit_per = 0.0;
        double p;
        int tag = 0;
        for (auto j = 0; j < 3; j++)
        {
            cin >> p;
            if (p > max_profit_per)
            {
                max_profit_per = p;
                tag = j;
            }
        }
        max_profit *= max_profit_per;
        res.push_back(int2char[tag]);
    }
    for (auto &el : res)
        cout << el << ' ';
    cout << fixed << setprecision(2) << (max_profit * 0.65 - 1) * 2;
    return 0;
}