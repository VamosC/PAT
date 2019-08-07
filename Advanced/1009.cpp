#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int exp_;
    double coeff_;
    shared_ptr<ListNode> next_;
    ListNode() : next_(nullptr) {}
    ListNode(int exp, double coeff) : exp_(exp), coeff_(coeff), next_(nullptr) {}
    ~ListNode() {}
};

shared_ptr<ListNode> addPoly(const shared_ptr<ListNode> &p, const shared_ptr<ListNode> &q)
{
    auto m = p->next_;
    auto n = q->next_;
    auto res = make_shared<ListNode>();
    auto tmp = res;
    while (m && n)
    {
        if (m->exp_ > n->exp_)
        {
            if (m->coeff_ != 0)
            {
                tmp->next_ = make_shared<ListNode>(m->exp_, m->coeff_);
                tmp = tmp->next_;
            }
            m = m->next_;
        }
        else if (m->exp_ == n->exp_)
        {
            if (m->coeff_ + n->coeff_ != 0)
            {
                tmp->next_ = make_shared<ListNode>(m->exp_, m->coeff_ + n->coeff_);
                tmp = tmp->next_;
            }
            m = m->next_;
            n = n->next_;
        }
        else
        {
            if (n->coeff_ != 0)
            {
                tmp->next_ = make_shared<ListNode>(n->exp_, n->coeff_);
                tmp = tmp->next_;
            }
            n = n->next_;
        }
    }
    while (m)
    {
        if (m->coeff_ != 0)
        {
            tmp->next_ = make_shared<ListNode>(m->exp_, m->coeff_);
            tmp = tmp->next_;
        }
        m = m->next_;
    }
    while (n)
    {
        if (n->coeff_ != 0)
        {
            tmp->next_ = make_shared<ListNode>(n->exp_, n->coeff_);
            tmp = tmp->next_;
        }
        n = n->next_;
    }
    return res;
}

shared_ptr<ListNode> mulItem(const shared_ptr<ListNode> &p, const shared_ptr<ListNode> &q)
{
    auto res = make_shared<ListNode>();
    auto tmp = res;
    auto m = q;
    while (m)
    {
        tmp->next_ = make_shared<ListNode>(m->exp_ + p->exp_, m->coeff_ * p->coeff_);
        tmp = tmp->next_;
        m = m->next_;
    }
    return res;
}

shared_ptr<ListNode> mulPoly(const shared_ptr<ListNode> &p, const shared_ptr<ListNode> &q)
{
    auto m = p->next_;
    auto n = q->next_;
    auto res = make_shared<ListNode>();
    while (m)
    {
        auto tmp = mulItem(m, n);
        res = addPoly(tmp, res);
        m = m->next_;
    }
    return res;
}

int main()
{
    int n;
    auto p = make_shared<ListNode>();
    auto q = make_shared<ListNode>();
    cin >> n;
    auto tmp = p;
    for (auto i = 0; i < n; i++)
    {
        int exp;
        double coeff;
        cin >> exp >> coeff;
        tmp->next_ = make_shared<ListNode>(exp, coeff);
        tmp = tmp->next_;
    }
    tmp = q;
    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        int exp;
        double coeff;
        cin >> exp >> coeff;
        tmp->next_ = make_shared<ListNode>(exp, coeff);
        tmp = tmp->next_;
    }
    auto res = mulPoly(p, q);
    tmp = res->next_;
    int size = 0;
    while (tmp)
    {
        size++;
        tmp = tmp->next_;
    }
    cout << size;
    tmp = res->next_;
    while (tmp)
    {
        cout << ' ' << tmp->exp_ << ' ' << fixed << setprecision(1) << tmp->coeff_;
        tmp = tmp->next_;
    }
    return 0;
}