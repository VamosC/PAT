// for OJ use this
// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

class ListNode
{
public:
    int exp_;
    double coeff_;
    shared_ptr<ListNode> next_;
    ListNode() : exp_(0), coeff_(0.0), next_(nullptr) {}
    ListNode(int exp, double coeff) : exp_(exp), coeff_(coeff), next_(nullptr) {}
    ~ListNode() {}
};

shared_ptr<ListNode> addPoly(shared_ptr<ListNode> &p, shared_ptr<ListNode> &q)
{
    shared_ptr<ListNode> res;
    if (p->next_ == nullptr)
        res = q;
    else if (q->next_ == nullptr)
        res = p;
    else
    {
        res = make_shared<ListNode>();
        auto tmp = res;
        auto p1 = p->next_;
        auto q1 = q->next_;
        while (p1 && q1)
        {
            if (p1->exp_ > q1->exp_)
            {
                if (p1->coeff_ != 0)
                {
                    tmp->next_ = make_shared<ListNode>(p1->exp_, p1->coeff_);
                    tmp = tmp->next_;
                }
                p1 = p1->next_;
            }
            else if (p1->exp_ == q1->exp_)
            {
                if (p1->coeff_ + q1->coeff_ != 0)
                {
                    tmp->next_ = make_shared<ListNode>(p1->exp_, p1->coeff_ + q1->coeff_);
                    tmp = tmp->next_;
                }

                p1 = p1->next_;
                q1 = q1->next_;
            }
            else
            {
                if (q1->coeff_ != 0)
                {
                    tmp->next_ = make_shared<ListNode>(q1->exp_, q1->coeff_);
                    tmp = tmp->next_;
                }
                q1 = q1->next_;
            }
        }
        while (p1)
        {
            if (p1->coeff_ != 0)
            {
                tmp->next_ = make_shared<ListNode>(p1->exp_, p1->coeff_);
                tmp = tmp->next_;
            }
            p1 = p1->next_;
        }
        while (q1)
        {
            if (q1->coeff_ != 0)
            {
                tmp->next_ = make_shared<ListNode>(q1->exp_, q1->coeff_);
                tmp = tmp->next_;
            }
            q1 = q1->next_;
        }
    }
    return res;
}

int main()
{
    auto p = make_shared<ListNode>();
    auto q = make_shared<ListNode>();
    int num;
    cin >> num;
    auto tmp = p;
    for (auto i = 0; i < num; i++)
    {
        int exp;
        double coeff;
        cin >> exp >> coeff;
        tmp->next_ = make_shared<ListNode>(exp, coeff);
        tmp = tmp->next_;
    }
    cin >> num;
    tmp = q;
    for (auto i = 0; i < num; i++)
    {
        int exp;
        double coeff;
        cin >> exp >> coeff;
        tmp->next_ = make_shared<ListNode>(exp, coeff);
        tmp = tmp->next_;
    }
    auto res = addPoly(p, q);
    auto size = 0;
    tmp = res->next_;
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
}