#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int l;

bool findwolf(const vector<int> &p, vector<int> &S, int i, int count, int liar, int flag)
{
    if (i == p.size())
    {
        if (liar == 0 && count == 0 && flag > -l && flag <= l)
        {
            return true;
        }
        return false;
    }
    if (count < 0 || liar < 0)
        return false;
    if (liar == 0 && flag == l)
        return false;
    if (liar == 0 && flag == -l)
        return false;
    if (S[i] == 0)
    {
        S[i] = 1;
        if (S[abs(p[i]) - 1] == 0)
        {
            if (p[i] < 0)
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 1, liar, flag))
                {
                    return true;
                }
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count, liar - 1, flag - 1))
                    return true;
            }
            else
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 1, liar - 1, flag - 1))
                    return true;
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count, liar, flag))
                {
                    return true;
                }
            }
            S[abs(p[i]) - 1] = 0;
        }
        else
        {
            if (S[abs(p[i]) - 1] * p[i] > 0)
            {
                if (findwolf(p, S, i + 1, count, liar, flag))
                    return true;
            }
            else
            {
                if (findwolf(p, S, i + 1, count, liar - 1, flag - 1))
                    return true;
            }
        }
        S[i] = -1;
        if (S[abs(p[i]) - 1] == 0)
        {
            if (p[i] < 0)
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 2, liar, flag))
                    return true;
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count - 1, liar - 1, flag + 1))
                    return true;
            }
            else
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 2, liar - 1, flag + 1))
                    return true;
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count - 1, liar, flag))
                {
                    return true;
                }
            }
            S[abs(p[i]) - 1] = 0;
        }
        else
        {
            if (S[abs(p[i]) - 1] * p[i] > 0)
            {
                if (findwolf(p, S, i + 1, count - 1, liar, flag))
                    return true;
            }
            else
            {
                if (findwolf(p, S, i + 1, count - 1, liar - 1, flag + 1))
                    return true;
            }
        }
        S[i] = 0;
    }
    else if (S[i] > 0)
    {
        if (S[abs(p[i]) - 1] == 0)
        {
            if (p[i] < 0)
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 1, liar, flag))
                {
                    return true;
                }
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count, liar - 1, flag - 1))
                    return true;
                S[abs(p[i]) - 1] = 0;
            }
            else
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 1, liar - 1, flag - 1))
                    return true;
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count, liar, flag))
                {
                    return true;
                }
                S[abs(p[i]) - 1] = 0;
            }
        }
        else
        {
            if (S[abs(p[i]) - 1] * p[i] > 0)
            {
                return findwolf(p, S, i + 1, count, liar, flag);
            }
            else
            {
                return findwolf(p, S, i + 1, count, liar - 1, flag - 1);
            }
        }
    }
    else if (S[i] < 0)
    {
        if (S[abs(p[i]) - 1] == 0)
        {
            if (p[i] < 0)
            {
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 1, liar, flag))
                {
                    return true;
                }
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count, liar - 1, flag + 1))
                    return true;
                S[abs(p[i]) - 1] = 0;
            }
            else
            {
                S[abs(p[i]) - 1] = 1;
                if (findwolf(p, S, i + 1, count, liar, flag))
                {
                    return true;
                }
                S[abs(p[i]) - 1] = -1;
                if (findwolf(p, S, i + 1, count - 1, liar - 1, flag + 1))
                    return true;
                S[abs(p[i]) - 1] = 0;
            }
        }
        else
        {
            if (S[abs(p[i]) - 1] * p[i] > 0)
            {
                return findwolf(p, S, i + 1, count, liar, flag);
            }
            else
            {
                return findwolf(p, S, i + 1, count, liar - 1, flag + 1);
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m >> l;
    vector<int> v(n);
    for (auto i = 0; i < n; ++i)
        cin >> v[i];
    vector<int> S(n, 0);
    if (findwolf(v, S, 0, m, l, 0))
    {
        bool flag = true;
        for (int i = n; i > 0; --i)
        {
            if (S[i] < 0)
            {
                if (flag)
                {
                    cout << i + 1;
                    flag = false;
                }
                else
                    cout << " " << i + 1;
            }
        }
    }
    else
    {
        cout << "No Solution\n";
    }

    return 0;
}