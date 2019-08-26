#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
    void insert(int key)
    {
        if (key <= val)
        {
            if (left == nullptr)
            {
                left = make_shared<TreeNode>(key);
            }
            else
            {
                left->insert(key);
            }
        }
        else
        {
            if (right == nullptr)
            {
                right = make_shared<TreeNode>(key);
            }
            else
            {
                right->insert(key);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    shared_ptr<TreeNode> root = nullptr;
    while (n > 0)
    {
        int key;
        cin >> key;
        if (root)
        {
            root->insert(key);
        }
        else
        {
            root = make_shared<TreeNode>(key);
        }
        n--;
    }
    deque<shared_ptr<TreeNode>> q;
    q.push_back(root);
    vector<int> level;
    level.push_back(1);
    int size = 1;
    while (!q.empty())
    {
        while (size > 0)
        {
            auto node = q.front();
            q.pop_front();
            if (node->left)
                q.push_back(node->left);
            if (node->right)
                q.push_back(node->right);
            size--;
        }
        size = q.size();
        if (size > 0)
        {
            level.push_back(size);
        }
    }
    if (level.size() == 1)
    {
        cout << "1 + 0 = 1" << '\n';
    }
    else
    {
        cout << level[level.size() - 1] << " + " << level[level.size() - 2] << " = " << level[level.size() - 1] + level[level.size() - 2] << '\n';
    }

    return 0;
}