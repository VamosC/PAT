// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
using namespace std;

class BNode
{
public:
    int val;
    shared_ptr<BNode> next;
    BNode() : next(nullptr) {}
    ~BNode() {}
};

class A
{
public:
    virtual void f() {cout << "A f" << '\n';}
    virtual int g() { cout << "A g" << '\n';return x; }
    int x;
};

class B : public A
{
public:
    void f() override { cout << "B f" << '\n';this->y = 2; }
    int y;
};

int main()
{
    B* a = new B();
    A* b = a;
    a->f();
    b->f();
    return 0;
}