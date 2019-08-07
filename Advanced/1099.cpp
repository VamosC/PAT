#include <bits/stdc++.h>
using namespace std;

struct BNode
{
    int val;
    shared_ptr<BNode> left;
    shared_ptr<BNode> right;
    BNode() : left(nullptr), right(nullptr) {}
    ~BNode() {}
};

void make_tree(vector<shared_ptr<BNode>> &tree, const vector<pair<int, int>> &children, int i)
{
    if (children[i].first != -1)
    {
        tree[i]->left = tree[children[i].first];
        make_tree(tree, children, children[i].first);
    }
    if (children[i].second != -1)
    {
        tree[i]->right = tree[children[i].second];
        make_tree(tree, children, children[i].second);
    }
}

void inOrder(shared_ptr<BNode> &node, const vector<int> &v, int &i)
{
    if (node->left)
    {
        inOrder(node->left, v, i);
    }
    node->val = v[i++];
    if (node->right)
    {
        inOrder(node->right, v, i);
    }
}

void levelOrder(const shared_ptr<BNode> &node)
{
    queue<shared_ptr<BNode>> v;
    if (node == nullptr)
        return;
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
            cout << " " << p->val;
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
    vector<shared_ptr<BNode>> searchT(n);
    vector<pair<int, int>> children;
    for (auto i = 0; i < n; i++)
        searchT[i] = make_shared<BNode>();
    for (auto i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        children.push_back(make_pair(a, b));
    }
    make_tree(searchT, children, 0);
    vector<int> v;
    for (auto i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int count = 0;
    inOrder(searchT[0], v, count);
    levelOrder(searchT[0]);
    return 0;
}