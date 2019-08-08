#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
};

void post_order(const shared_ptr<TreeNode> &node, int i)
{
    if (node == nullptr)
        return;
    if (node->left)
        post_order(node->left, i + 1);
    if (node->right)
        post_order(node->right, i + 1);
    if (i == 0)
        cout << node->val;
    else
        cout << node->val << ' ';
}

int main()
{
    int n;
    cin >> n;
    vector<shared_ptr<TreeNode>> tree(n);
    stack<shared_ptr<TreeNode>> s;
    for (auto i = 0; i < n; ++i)
    {
        tree[i] = make_shared<TreeNode>();
        tree[i]->val = i + 1;
    }
    shared_ptr<TreeNode> tmp = nullptr;
    int root;
    for (auto i = 0; i < n * 2; ++i)
    {
        string op;
        int index;
        cin >> op;
        if (op == "Push")
        {
            cin >> index;
            if (!s.empty())
            {
                auto p = s.top();
                if (tmp == nullptr)
                    p->left = tree[index - 1];
                else
                {
                    tmp->right = tree[index - 1];
                    tmp = nullptr;
                }
            }
            else
            {
                if (tmp == nullptr)
                    root = index;
                else
                {
                    tmp->right = tree[index - 1];
                    tmp = nullptr;
                }
            }
            s.push(tree[index - 1]);
        }
        else
        {
            tmp = s.top();
            s.pop();
        }
    }
    post_order(tree[root - 1], 0);
    return 0;
}