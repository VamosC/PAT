#include <bits/stdc++.h>

using namespace std;

struct Student
{
    int C;
    int M;
    int E;
    int A;
};

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, Student> s;
    for (auto i = 0; i < n; ++i)
    {
        Student t;
        string id;
        cin >> id >> t.C >> t.M >> t.E;
        t.A = (t.C + t.M + t.E) / 3;
        s[id] = t;
    }
    for (auto i = 0; i < m; ++i)
    {
        string search;
        cin >> search;
        if (s.count(search) == 0)
            cout << "N/A\n";
        else
        {
            Student t = s[search];
            int a = 1;
            int b = 1;
            int c = 1;
            int d = 1;
            for (auto it = s.begin(); it != s.end(); ++it)
            {
                if (it->first != search)
                {
                    if (it->second.A > t.A)
                        a++;
                    if (it->second.C > t.C)
                        b++;
                    if (it->second.M > t.M)
                        c++;
                    if (it->second.E > t.E)
                        d++;
                }
            }
            if(a <= b)
            {
                if(a <= c)
                {
                    if (a <= d)
                    {
                        cout << a << " A\n";
                    }
                    else
                    {
                        cout << d << " E\n";
                    }
                }
                else
                {
                    if(c <= d)
                    {
                        cout << c << " M\n";
                    }
                    else
                    {
                        cout << d << " E\n";
                    }
                }
            }
            else
            {
                if(b <= c)
                {
                    if(b <= d)
                    {
                        cout << b << " C\n";
                    }
                    else
                    {
                        cout << d << " E\n";
                    }
                }
                else
                {
                    if(c <= d)
                    {
                        cout << c << " M\n";
                    }
                    else
                    {
                        cout << d << " E\n";
                    }
                }
            }
            
        }
    }
    return 0;
}