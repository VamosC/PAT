#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
};

shared_ptr<TreeNode> make_subtree(const vector<int> &p, const vector<int> &q, int &i, int l, int r, bool searchFlags, bool *flag)
{
    if (i < p.size())
    {
        if (l > r)
            return nullptr;
        auto node = make_shared<TreeNode>();
        node->val = p[i];
        int index = -1;
        if (searchFlags)
        {
            for (auto j = l; j <= r; ++j)
            {
                if (p[i] == q[j])
                {
                    index = j;
                    break;
                }
            }
        }
        else
        {
            for (auto j = r; j >= l; --j)
            {
                if (p[i] == q[j])
                {
                    index = j;
                    break;
                }
            }
        }

        if (index == -1)
        {
            *flag = false;
            return nullptr;
        }
        i++;
        if (index > l)
        {
            node->left = make_subtree(p, q, i, l, index - 1, searchFlags, flag);
        }
        if (index < r)
        {
            node->right = make_subtree(p, q, i, index + 1, r, searchFlags, flag);
        }
        return node;
    }
    return nullptr;
}

shared_ptr<TreeNode> make_tree(const vector<int> &p, bool *flag)
{
    vector<int> s(p);
    sort(s.begin(), s.end());
    int i = 0;
    bool success = true;
    auto node = make_subtree(p, s, i, 0, p.size() - 1, true, &success);
    if (!success)
    {
        i = 0;
        sort(s.begin(), s.end(), [](int a, int b) { return a > b; });
        success = true;
        node = make_subtree(p, s, i, 0, p.size() - 1, false, &success);
        if (!success)
        {
            *flag = false;
            return nullptr;
        }
    }
    return node;
}

void post_order(const shared_ptr<TreeNode> &node, int i)
{
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
    vector<int> pre(n);
    bool flag = true;
    for (auto i = 0; i < n; i++)
        cin >> pre[i];
    auto node = make_tree(pre, &flag);
    if (flag)
    {
        cout << "YES\n";
        post_order(node, 0);
    }
    else
    {
        cout << "NO";
    }
    return 0;
}