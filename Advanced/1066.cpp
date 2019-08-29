// #include <bits/stdc++.h>
#include <memory>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    int h;
    shared_ptr<Node> l;
    shared_ptr<Node> r;
    Node() : h(0), l(nullptr), r(nullptr) {}
    static shared_ptr<Node> insert(shared_ptr<Node> &p, int key)
    {
        if (key < p->val)
        {
            if (p->l == nullptr)
            {
                p->l = make_shared<Node>();
                p->l->val = key;
                p->h = max(height(p->l), height(p->r)) + 1;
                return p;
            }
            else
            {
                p->l = insert(p->l, key);
                if (height(p->l) - height(p->r) > 1)
                {
                    if (key < p->l->val)
                    {
                        return rr(p);
                    }
                    else if (key > p->l->val)
                    {
                        return lr(p);
                    }
                }
                p->h = max(p->l->h, p->r->h) + 1;
            }
        }
        else if (key > p->val)
        {
            if (p->r == nullptr)
            {
                p->r = make_shared<Node>();
                p->r->val = key;
                p->h = max(height(p->l), height(p->r)) + 1;
                return p;
            }
            else
            {
                p->r = insert(p->r, key);
                if (height(p->r) - height(p->l) > 1)
                {
                    if (key > p->r->val)
                    {
                        return ll(p);
                    }
                    else if (key < p->r->val)
                    {
                        return rl(p);
                    }
                }
                p->h = max(p->l->h, p->r->h) + 1;
            }
        }
        return p;
    }
    static shared_ptr<Node> ll(shared_ptr<Node> &p)
    {
        auto node = p->r;
        p->r = node->l;
        node->l = p;
        p->h = max(height(p->l), height(p->r)) + 1;
        node->h = max(height(node->r), p->h) + 1;
        return node;
    }

    static shared_ptr<Node> lr(shared_ptr<Node> &p)
    {
        p->l = ll(p->l);
        return rr(p);
    }

    static shared_ptr<Node> rl(shared_ptr<Node> &p)
    {
        p->r = rr(p->r);
        return ll(p);
    }

    static shared_ptr<Node> rr(shared_ptr<Node> &p)
    {
        auto node = p->l;
        p->l = node->r;
        node->r = p;
        p->h = max(height(p->l), height(p->r)) + 1;
        node->h = max(height(node->l), p->h) + 1;
        return node;
    }

    static int height(const shared_ptr<Node> &node)
    {
        if (node == nullptr)
            return -1;
        return node->h;
    }
};

int main()
{
    int n;
    cin >> n;
    shared_ptr<Node> root;
    int key;
    for (auto i = 0; i < n; ++i)
    {
        cin >> key;
        if (i == 0)
        {
            root = make_shared<Node>();
            root->val = key;
        }
        else
        {
            root = root->insert(root, key);
        }
    }
    cout << root->val << '\n';
    return 0;
}