// For OJ use this
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Person
{
public:
    string id;
    int in_h;
    int in_m;
    int in_s;
    int out_h;
    int out_m;
    int out_s;
    Person() {}
    Person(const Person &p)
    {
        id = p.id;
        in_h = p.in_h;
        in_m = p.in_m;
        in_s = p.in_s;
        out_h = p.out_h;
        out_m = p.out_m;
        out_s = p.out_s;
    }
    ~Person() {}
    friend istream &operator>>(istream &in, Person &p);
};

istream &operator>>(istream &in, Person &p)
{
    in >> p.id;
    string sign_in, sign_out;
    in >> sign_in >> sign_out;
    p.in_h = atoi(sign_in.substr(0, 2).c_str());
    p.in_m = atoi(sign_in.substr(3, 2).c_str());
    p.in_s = atoi(sign_in.substr(6, 2).c_str());
    p.out_h = atoi(sign_out.substr(0, 2).c_str());
    p.out_m = atoi(sign_out.substr(3, 2).c_str());
    p.out_s = atoi(sign_out.substr(6, 2).c_str());
    return in;
}

int main()
{
    int num;
    cin >> num;
    vector<Person> v;
    for (auto i = 0; i < num; i++)
    {
        Person tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), [](Person &p, Person &q) {
        if (p.in_h == q.in_h)
        {
            if (p.in_m == q.in_m)
            {
                if (p.in_s == q.in_s)
                {
                    return true;
                }
                else
                {
                    return p.in_s < q.in_s;
                }
            }
            else
            {
                return p.in_m < q.in_m;
            }
        }
        else
        {
            return p.in_h < q.in_h;
        }
    });
    cout << v[0].id << ' ';
    sort(v.begin(), v.end(), [](Person &p, Person &q) {
        if (p.out_h == q.out_h)
        {
            if (p.out_m == q.out_m)
            {
                if (p.out_s == q.out_s)
                {
                    return true;
                }
                else
                {
                    return p.out_s > q.out_s;
                }
            }
            else
            {
                return p.out_m > q.out_m;
            }
        }
        else
        {
            return p.out_h > q.out_h;
        }
    });
    cout << v[0].id;
    return 0;
}