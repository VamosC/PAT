#include <bits/stdc++.h>

using namespace std;

struct Student
{
    int id;
    string name;
    int grade;
    Student(int id, string name, int grade)
        : id(id), name(move(name)), grade(grade) {}
};

int main()
{
    int n, c;
    cin >> n >> c;
    vector<Student> v;
    for (auto i = 0; i < n; ++i)
    {
        int id, grade;
        string name;
        cin >> id >> name >> grade;
        v.emplace_back(id, name, grade);
    }
    switch (c)
    {
    case 1:
    {
        sort(v.begin(), v.end(), [](const Student &a, const Student &b) { return a.id < b.id; });
        break;
    }
    case 2:
    {
        sort(v.begin(), v.end(), [](const Student &a, const Student &b) {if(a.name == b.name){return a.id < b.id;}else{return a.name < b.name;} });
        break;
    }
    case 3:
    {
        sort(v.begin(), v.end(), [](const Student &a, const Student &b) {if(a.grade == b.grade){return a.id < b.id;}else{return a.grade < b.grade;} });
        break;
    }
    default:
        break;
    }
    for (auto it : v)
    {
        printf("%06d", it.id);
        cout << " " << it.name << " " << it.grade << '\n';
    }
    return 0;
}