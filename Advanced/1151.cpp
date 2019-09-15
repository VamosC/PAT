#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    shared_ptr<Node> parent;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    Node() : parent(nullptr), left(nullptr), right(nullptr) {}
};

shared_ptr<Node> buildTree(const vector<int> &in, const vector<int> &pre, unordered_map<int, shared_ptr<Node>> &tree, int &i, int l, int r)
{
    if (l > r)
    {
        return nullptr;
    }
    int j;
    int root = i;
    i++;
    tree[pre[root]]->val = pre[root];
    for (j = l; j <= r; ++j)
    {
        if (in[j] == pre[root])
            break;
    }
    tree[pre[root]]->left = buildTree(in, pre, tree, i, l, j - 1);
    if (tree[pre[root]]->left != nullptr)
        tree[pre[root]]->left->parent = tree[pre[root]];
    tree[pre[root]]->right = buildTree(in, pre, tree, i, j + 1, r);
    if (tree[pre[root]]->right != nullptr)
        tree[pre[root]]->right->parent = tree[pre[root]];
    return tree[pre[root]];
}

int main()
{
    int N, M;
    cin >> M >> N;
    unordered_map<int, shared_ptr<Node>> tree;
    vector<int> in, pre;
    for (auto i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        in.push_back(x);
        tree[x] = make_shared<Node>();
    }
    for (auto i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        pre.push_back(x);
    }
    int i = 0;
    buildTree(in, pre, tree, i, 0, N - 1);
    for (auto j = 0; j < M; j++)
    {
        int x, y;
        cin >> x >> y;
        if (tree.count(x) == 0 || tree.count(y) == 0)
        {
            if (tree.count(x) == 0 && tree.count(y) == 0)
            {
                cout << "ERROR: " << x << " and " << y << " are not found.\n";
            }
            else if (tree.count(x) == 0)
            {
                cout << "ERROR: " << x << " is not found.\n";
            }
            else
            {
                cout << "ERROR: " << y << " is not found.\n";
            }
        }
        else
        {
            if (tree[x]->parent == tree[y])
            {
                cout << y << " is an ancestor of " << x << ".\n";
            }
            else if (tree[y]->parent == tree[x])
            {
                cout << x << " is an ancestor of " << y << ".\n";
            }
            else
            {
                vector<int> path1, path2;
                auto root = tree[x];
                while (root != nullptr)
                {
                    path1.push_back(root->val);
                    root = root->parent;
                }
                root = tree[y];
                while (root != nullptr)
                {
                    path2.push_back(root->val);
                    root = root->parent;
                }
                int ancestor;
                for (auto p = path1.rbegin(), q = path2.rbegin(); p != path1.rend() && q != path2.rend(); p++, q++)
                {
                    if (*p != *q)
                    {
                        break;
                    }
                    ancestor = *p;
                }
                if (ancestor == x)
                {
                    cout << x << " is an ancestor of " << y << ".\n";
                }
                else if (ancestor == y)
                {
                    cout << y << " is an ancestor of " << x << ".\n";
                }
                else
                {
                    cout << "LCA of " << x << " and " << y << " is " << ancestor << ".\n";
                }
            }
        }
    }
    return 0;
}