#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> t;
    string x;
    for (auto i = 0; i < n; ++i)
    {
        int score;
        cin >> x >> score;
        t.push_back(make_pair(move(x), score));
    }
    vector<pair<string, int>> res;
    unordered_map<string, int> nums;
    for (auto i = 0; i < m; ++i)
    {
        int type;
        string term;
        cin >> type >> term;
        switch (type)
        {
        case 1:
        {
            res.clear();
            for (auto it : t)
            {
                if (it.first[0] == term[0])
                {
                    res.push_back(it);
                }
            }
            cout << "Case " << i + 1 << ": " << type << " " << term << '\n';
            if (res.empty())
            {
                cout << "NA\n";
                break;
            }
            sort(res.begin(), res.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
                if (a.second != b.second)
                    return a.second > b.second;
                return a.first < b.first;
            });
            for (auto it : res)
            {
                cout << it.first << " " << it.second << '\n';
            }
            break;
        }
        case 2:
        {
            int total_score = 0;
            int total_num = 0;
            for (auto it : t)
            {
                if (it.first.substr(1, 3) == term)
                {
                    total_score += it.second;
                    total_num++;
                }
            }
            cout << "Case " << i + 1 << ": " << type << " " << term << '\n';
            if (total_num == 0)
            {
                cout << "NA\n";
                break;
            }
            cout << total_num << " " << total_score << '\n';
            break;
        }
        case 3:
        {
            nums.clear();
            res.clear();
            for (auto it : t)
            {
                if (it.first.substr(4, 6) == term)
                {
                    if (nums.count(it.first.substr(1, 3)) == 0)
                        nums[it.first.substr(1, 3)] = 1;
                    else
                        nums[it.first.substr(1, 3)]++;
                }
            }
            cout << "Case " << i + 1 << ": " << type << " " << term << '\n';
            if (nums.empty())
            {
                cout << "NA\n";
                break;
            }
            for (auto it : nums)
            {
                res.push_back(make_pair(it.first, it.second));
            }
            sort(res.begin(), res.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
                if (a.second != b.second)
                    return a.second > b.second;
                return a.first < b.first;
            });
            for (auto it : res)
            {
                cout << it.first << " " << it.second << '\n';
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}