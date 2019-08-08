#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    unordered_map<int, string> low_table = {
        {0, "tret"},
        {1, "jan"},
        {2, "feb"},
        {3, "mar"},
        {4, "apr"},
        {5, "may"},
        {6, "jun"},
        {7, "jly"},
        {8, "aug"},
        {9, "sep"},
        {10, "oct"},
        {11, "nov"},
        {12, "dec"}};
    unordered_map<string, int> r_table = {
        {"tret", 0},
        {"jan", 1},
        {"feb", 2},
        {"mar", 3},
        {"apr", 4},
        {"may", 5},
        {"jun", 6},
        {"jly", 7},
        {"aug", 8},
        {"sep", 9},
        {"oct", 10},
        {"nov", 11},
        {"dec", 12},
        {"tam", 13},
        {"hel", 26},
        {"maa", 39},
        {"huh", 52},
        {"tou", 65},
        {"kes", 78},
        {"hei", 91},
        {"elo", 104},
        {"syy", 117},
        {"lok", 130},
        {"mer", 143},
        {"jou", 156}};
    unordered_map<int, string> high_table = {
        {1, "tam"},
        {2, "hel"},
        {3, "maa"},
        {4, "huh"},
        {5, "tou"},
        {6, "kes"},
        {7, "hei"},
        {8, "elo"},
        {9, "syy"},
        {10, "lok"},
        {11, "mer"},
        {12, "jou"}};
    cin >> n;
    getchar();
    string res;
    for (auto i = 0; i < n; i++)
    {
        string s;
        res.clear();
        getline(cin, s);
        auto filter_space = s.find_first_not_of(' ');
        if (filter_space != 0)
            s = s.substr(filter_space);
        if (s[0] >= '0' && s[0] <= '9')
        {
            int num = 0;
            for (auto c : s)
            {
                if (c >= '0' && c <= '9')
                {
                    num *= 10;
                    num += (c - '0');
                }
                else
                    break;
            }
            if (num == 0)
            {
                res.insert(0, low_table[0]);
                cout << res << '\n';
                continue;
            }
            if (num % 13 != 0)
            {
                res.insert(0, low_table[num % 13]);
                if (num / 13 > 0)
                    res.insert(0, " ");
            }
            num /= 13;
            if (num > 0)
            {
                res.insert(0, high_table[num]);
            }
            cout << res << '\n';
        }
        else
        {
            int num;
            auto pos = s.find(' ');
            if (pos != string::npos)
            {
                num = r_table[s.substr(0, pos)];
                auto pos1 = s.find_first_not_of(' ', pos);
                if (pos1 != string::npos)
                {
                    auto pos2 = s.find(' ', pos1);
                    if (pos2 != string::npos)
                    {
                        num += r_table[s.substr(pos1, pos2 - pos1)];
                    }
                    else
                    {
                        num += r_table[s.substr(pos1)];
                    }
                }
            }
            else
            {
                num = r_table[s];
            }
            cout << num << '\n';
        }
    }
    return 0;
}