#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int curr;
    Node(int val_, int curr_) : val(val_), curr(curr_) {}
};

int main()
{
    int n;
    int root;
    vector<Node> v;
    unordered_map<int, int> r;
    unordered_map<int, int> s;
    cin >> n >> root;
    for (auto i = 0; i < n; ++i)
    {
        int curr, next, key;
        cin >> curr >> key >> next;
        r[curr] = next;
        s[curr] = key;
    }
    if (s.count(root) == 0)
    {
        cout << "0 " << root << '\n';
        return 0;
    }
    while (root != -1)
    {
        v.emplace_back(s[root], root);
        root = r[root];
    }
    sort(v.begin(), v.end(), [](const Node &a, const Node &b) { return a.val < b.val; });
    cout << v.size() << " ";
    printf("%05d\n", v.front().curr);
    for (auto i = 0; i < v.size(); ++i)
    {
        printf("%05d ", v[i].curr);
        cout << v[i].val << " ";
        if (i + 1 < v.size())
        {
            printf("%05d\n", v[i + 1].curr);
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}