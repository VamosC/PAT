#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

struct Node
{
    string val;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    Node() : left(nullptr), right(nullptr) {}
};
shared_ptr<Node> RR;

void infix(const shared_ptr<Node> &root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->val;
        return;
    }
    if (root->val == "+" || root->val == "-")
    {
        if (root->left == nullptr)
        {
            if (root != RR)
                cout << "(";
            cout << root->val;
            if (root->right->left && root->right->right)
                cout << "(";
            infix(root->right);
            if (root->right->left && root->right->right)
                cout << ")";
            if (root != RR)
                cout << ")";
            return;
        }
    }
    if (root->left)
    {
        if (root->left->left && root->left->right)
            cout << "(";
        infix(root->left);
        if (root->left->left && root->left->right)
            cout << ")";
    }
    cout << root->val;
    if (root->right)
    {
        if (root->right->left && root->right->right)
            cout << "(";
        infix(root->right);
        if (root->right->left && root->right->right)
            cout << ")";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<shared_ptr<Node>> v;
    vector<bool> visit(n + 1, true);
    for (auto i = 0; i < n + 1; ++i)
    {
        v.push_back(make_shared<Node>());
    }
    for (auto i = 0; i < n; ++i)
    {
        string s;
        int x, y;
        cin >> s >> x >> y;
        v[i + 1]->val = move(s);
        if (x != -1)
        {
            v[i + 1]->left = v[x];
            visit[x] = false;
        }
        if (y != -1)
        {
            v[i + 1]->right = v[y];
            visit[y] = false;
        }
    }
    int index = 1;
    while (index <= n)
    {
        if (visit[index])
            break;
        index++;
    }
    RR = v[index];
    infix(v[index]);
    return 0;
}