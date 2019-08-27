#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    string curr_;
    string next_;
    shared_ptr<Node> next;
    Node() : next(nullptr) {}
};

int main()
{
    unordered_map<string, shared_ptr<Node>> v;
    set<int> s;
    string root_addr;
    int n;
    cin >> root_addr >> n;
    string curr, next;
    int val;
    for (auto i = 0; i < n; ++i)
    {
        curr.clear();
        next.clear();
        cin >> curr >> val >> next;
        auto node = make_shared<Node>();
        node->curr_ = move(curr);
        node->next_ = move(next);
        node->val = val;
        v[node->curr_] = node;
    }
    auto r = root_addr;
    while (true)
    {
        auto node = v[r];
        assert(r == node->curr_);
        if (node->next_ == "-1")
            break;
        node->next = v[node->next_];
        r = node->next_;
    }
    auto node = v[root_addr];
    string removed_addr;
    shared_ptr<Node> removed = nullptr;
    shared_ptr<Node> pre = nullptr;
    while (node)
    {
        auto abs_val = abs(node->val);
        if (s.count(abs_val) == 0)
        {
            s.insert(abs_val);
            pre = node;
            node = node->next;
        }
        else
        {
            if (removed_addr.empty())
            {
                removed_addr = node->curr_;
            }
            pre->next = node->next;
            if (node->next != nullptr)
            {
                pre->next_ = node->next->curr_;
            }
            else
            {
                pre->next_ = "-1";
            }
            node->next = nullptr;
            node->next_ = "-1";
            if (removed == nullptr)
            {
                removed = node;
            }
            else
            {
                removed->next = node;
                removed->next_ = node->curr_;
                removed = removed->next;
            }
            node = pre->next;
        }
    }
    auto p = root_addr;
    while (true)
    {
        if (p == "-1")
            break;
        cout << v[p]->curr_ << " " << v[p]->val << " " << v[p]->next_ << '\n';
        p = v[p]->next_;
    }
    p = removed_addr;
    if (p.empty())
        return 0;
    while (true)
    {
        if (p == "-1")
            break;
        cout << v[p]->curr_ << " " << v[p]->val << " " << v[p]->next_ << '\n';
        p = v[p]->next_;
    }
    return 0;
}