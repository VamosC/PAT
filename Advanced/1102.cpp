#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
};

void invert(shared_ptr<TreeNode> &node)
{
    if (node == nullptr)
        return;
    invert(node->left);
    invert(node->right);
    auto lnode = node->left;
    node->left = node->right;
    node->right = lnode;
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
        {
            cout << ' ' << p->val;
        }
        v.pop();
        if (p->left)
            v.push(p->left);
        if (p->right)
            v.push(p->right);
    }
    cout << '\n';
}

void inorder(const shared_ptr<TreeNode> &node, int &i)
{
    if (node == nullptr)
        return;
    if (node->left)
        inorder(node->left, i);
    if (i == 0)
    {
        cout << node->val;
        i++;
    }
    else
        cout << ' ' << node->val;
    if (node->right)
        inorder(node->right, i);
}

int main()
{
    int n;
    cin >> n;
    vector<shared_ptr<TreeNode>> tree(n);
    vector<bool> visit(n, false);
    for (auto i = 0; i < n; ++i)
    {
        tree[i] = make_shared<TreeNode>();
        tree[i]->val = i;
    }
    for (auto i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (a != "-")
        {
            tree[i]->left = tree[a[0] - '0'];
            visit[a[0] - '0'] = true;
        }
        if (b != "-")
        {
            tree[i]->right = tree[b[0] - '0'];
            visit[b[0] - '0'] = true;
        }
    }
    int index;
    for (auto i = 0; i < n; ++i)
        if (visit[i] == false)
            index = i;
    auto root = tree[index];
    invert(root);
    level_order(root);
    int i = 0;
    inorder(root, i);
    return 0;
}