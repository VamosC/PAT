// For OJ use this
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, vector<int>> family;
    int n, m;
    cin >> n >> m;
    for (auto i = 0; i < m; i++)
    {
        int parent, child;
        int num;
        cin >> parent;
        cin >> num;
        for (auto j = 0; j < num; j++)
        {
            cin >> child;
            family[parent].push_back(child);
        }
    }
    queue<int> v;
    vector<int> res;
    v.push(1);
    int size = 1;
    while (!v.empty())
    {
        auto count = 0;
        while (size != 0)
        {
            auto p = v.front();
            v.pop();
            if (family.count(p) == 0)
                count++;
            else
            {
                auto tmp = family[p];
                for (auto &el : tmp)
                    v.push(el);
            }
            size--;
        }
        res.push_back(count);
        size = v.size();
    }
    for (auto i = 0; i < res.size() - 1; i++)
        cout << res[i] << ' ';
    cout << res.back();
    return 0;
}