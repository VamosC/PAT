// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <memory>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
};
shared_ptr<TreeNode> make_tree(const vector<int> &p, const vector<int> &q, int &i, int l, int r)
{
    if (i >= 0)
    {
        auto node = make_shared<TreeNode>();
        node->val = p[i];
        int index = -1;
        for (auto j = 0; j < q.size(); ++j)
        {
            if (p[i] == q[j])
            {
                index = j;
                break;
            }
        }
        i--;
        if (index < r)
        {
            node->right = make_tree(p, q, i, index + 1, r);
        }
        if (index > l)
        {
            node->left = make_tree(p, q, i, l, index - 1);
        }
        return node;
    }
    return nullptr;
}

void level_order(const shared_ptr<TreeNode> &node)
{
    if (node == nullptr)
        return;
    queue<shared_ptr<TreeNode>> v;
    v.push(node);
    bool flag = true;
    while (!v.empty())
    {
        auto p = v.front();
        if (flag)
        {
            cout << p->val;
            flag = false;
        }
        else
            cout << ' ' << p->val;
        if (p->left)
            v.push(p->left);
        if (p->right)
            v.push(p->right);
        v.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> post(n);
    vector<int> in(n);
    for (auto i = 0; i < n; i++)
        cin >> post[i];
    for (auto i = 0; i < n; i++)
        cin >> in[i];
    int pos = n - 1;
    auto node = make_tree(post, in, pos, 0, n - 1);
    level_order(node);
    return 0;
}