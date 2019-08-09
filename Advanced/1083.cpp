#include <bits/stdc++.h>

using namespace std;
struct student
{
    string name;
    string id;
    int grade;
};

int main()
{
    int n;
    cin >> n;
    vector<student> v(n);
    for (auto i = 0; i < n; ++i)
    {
        cin >> v[i].name >> v[i].id >> v[i].grade;
    }
    int high, low;
    cin >> low >> high;
    sort(v.begin(), v.end(), [](student a, student b) { return a.grade > b.grade; });
    int count = 0;
    for (auto i = 0; i < v.size(); ++i)
    {
        if (v[i].grade <= high && v[i].grade >= low)
        {
            count++;
            cout << v[i].name << ' ' << v[i].id << '\n';
        }
        else if (v[i].grade < low)
        {
            break;
        }
    }
    if (count == 0)
        cout << "NONE";
    return 0;
}