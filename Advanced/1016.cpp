#include <bits/stdc++.h>

using namespace std;

struct Record
{
    int month;
    int day;
    int minute;
    int seconds;
    int status;
};

int main()
{
    vector<int> cost(24);
    for (auto i = 0; i < 24; ++i)
    {
        cin >> cost[i];
    }
    int n;
    cin >> n;
    map<string, vector<Record>> t;
    for (auto i = 0; i < n; ++i)
    {
        Record r;
        string name, date, status;
        cin >> name >> date >> status;
        sscanf(date.c_str(), "%d:%d:%d:%d", &r.month, &r.day, &r.minute, &r.seconds);
        r.status = status[1] == 'f' ? 1 : 0;
        t[name].push_back(r);
    }
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        bool flag = true;
        auto &v = it->second;
        sort(v.begin(), v.end(), [](const Record &a, const Record &b) {
            if (a.month != b.month)
                return a.month < b.month;
            else
            {
                if (a.day != b.day)
                    return a.day < b.day;
                else
                {
                    if (a.minute != b.minute)
                        return a.minute < b.minute;
                    else
                    {
                        return a.seconds < b.seconds;
                    }
                }
            }
        });
        double sum = 0.0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (i + 1 < v.size())
            {
                if (v[i].status == 0 && v[i + 1].status == 1)
                {
                    int total = 0;
                    double price = 0.0;
                    for (auto j = v[i].day; j <= v[i + 1].day; ++j)
                    {
                        int k = v[i].minute;
                        int e = v[i + 1].minute;
                        if (j != v[i].day)
                            k = 0;
                        if (j != v[i + 1].day)
                            e = 24;
                        for (auto c = k; c < e; c++)
                        {
                            total += cost[c] * 60;
                        }
                    }
                    total -= (cost[v[i].minute] * v[i].seconds);
                    total += (cost[v[i + 1].minute] * v[i + 1].seconds);
                    price = total / 100.0;
                    if (total != 0)
                    {
                        if (flag)
                        {
                            cout << it->first << " ";
                            printf("%02d\n", v[0].month);
                            flag = false;
                        }
                        printf("%02d:%02d:%02d ", v[i].day, v[i].minute, v[i].seconds);
                        printf("%02d:%02d:%02d ", v[i + 1].day, v[i + 1].minute, v[i + 1].seconds);
                        cout << ((v[i + 1].day - v[i].day) * 24 * 60 + (v[i + 1].minute - v[i].minute) * 60 + (v[i + 1].seconds - v[i].seconds)) << " ";
                        cout << "$";
                        printf("%.2lf\n", price);
                        sum += price;
                    }
                    i++;
                }
            }
        }
        if (sum != 0.0)
        {
            cout << "Total amount: $";
            printf("%.2lf\n", sum);
        }
    }
    return 0;
}