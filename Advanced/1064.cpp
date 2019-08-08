#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
};

void make_tree(shared_ptr<TreeNode> &v, const vector<int> &in, int &i)
{
    if (v->left)
        make_tree(v->left, in, i);
    v->val = in[i++];
    if (v->right)
        make_tree(v->right, in, i);
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
        v.pop();
        if (p->left)
            v.push(p->left);
        if (p->right)
            v.push(p->right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<shared_ptr<TreeNode>> tree(n);
    for (auto i = 0; i < n; ++i)
    {
        cin >> v[i];
        tree[i] = make_shared<TreeNode>();
    }
    sort(v.begin(), v.end());
    for (auto i = 0; i < n; ++i)
    {
        if (2 * i + 1 < n)
            tree[i]->left = tree[2 * i + 1];
        if (2 * i + 2 < n)
            tree[i]->right = tree[2 * i + 2];
    }
    int i = 0;
    make_tree(tree[0], v, i);
    level_order(tree[0]);
    return 0;
}