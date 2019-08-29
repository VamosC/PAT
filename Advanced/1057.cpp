#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    vector<int> v;
    stack<int> val;
    stack<int> before;
    stack<int> after;
    Stack()
    {
    }
    void push(int key)
    {
        v.push_back(key);
        if (val.empty())
            val.push(key);
        else if (v.size() == 2)
        {
            if (key < v.back())
            {
                val.push(key);
            }
            else
            {
                val.push(v.back());
            }
        }
        else if (v.size() == 3)
        {
            vector<int> tmp(v);
            sort(tmp.begin(), tmp.end());
            val.push(v[1]);
            before.push(v[0]);
            after.push(v[2]);
        }
        else
        {
            if (key < before.top())
            {
            }
        }
    }
    int pop()
    {
        auto key = v.back();
        v.pop_back();
        return key;
    }
    bool empty()
    {
        return v.empty();
    }
    int median()
    {
    }
};

int main()
{
    int n;
    cin >> n;
    Stack s;
    string command;
    for (auto i = 0; i < n; ++i)
    {
        command.clear();
        cin >> command;
        if (command[1] == 'o')
        {
            if (s.empty())
            {
                cout << "Invalid\n";
            }
            else
            {
                cout << s.pop() << '\n';
            }
        }
        else if (command[1] == 'e')
        {
            if (s.empty())
            {
                cout << "Invalid\n";
            }
            else
            {
                cout << s.median() << '\n';
            }
        }
        else if (command[1] == 'u')
        {
            int key;
            cin >> key;
            s.push(key);
        }
    }
    return 0;
}