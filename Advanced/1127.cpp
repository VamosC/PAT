#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    shared_ptr<Node> l;
    shared_ptr<Node> r;
    Node() : l(nullptr), r(nullptr) {}
};

void buildTree(shared_ptr<Node> &node, const vector<int> &in, const vector<int> &post, int l, int r, int &i)
{
    if (l > r)
    {
        return;
    }
    if (node == nullptr)
    {
        node = make_shared<Node>();
        node->val = post[i];
        int k;
        for (k = l; k <= r; ++k)
        {
            if (in[k] == post[i])
                break;
        }
        --i;
        buildTree(node->r, in, post, k + 1, r, i);
        buildTree(node->l, in, post, l, k - 1, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> post(n);
    for (auto i = 0; i < n; ++i)
        cin >> in[i];
    for (auto i = 0; i < n; ++i)
        cin >> post[i];
    int i = n - 1;
    shared_ptr<Node> node = nullptr;
    buildTree(node, in, post, 0, n - 1, i);
    deque<shared_ptr<Node>> q;
    q.push_back(node);
    stack<int> s;
    int size = q.size();
    int level = 1;
    bool flag = true;
    while (!q.empty())
    {
        while (size > 0)
        {
            auto p = q.front();
            q.pop_front();
            if (p->l)
                q.push_back(p->l);
            if (p->r)
                q.push_back(p->r);
            if (level % 2 == 0)
            {
                cout << " " << p->val;
            }
            else
            {
                s.push(p->val);
            }
            size--;
        }
        size = q.size();
        if (level % 2 == 1)
        {
            while (!s.empty())
            {
                if (flag)
                {
                    cout << s.top();
                    s.pop();
                    flag = false;
                }
                else
                {
                    cout << " " << s.top();
                    s.pop();
                }
            }
        }
        level++;
    }
    return 0;
}