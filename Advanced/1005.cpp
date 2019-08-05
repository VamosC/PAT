// For OJ use this
// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int computeSum(string &s)
{
    int sum = 0;
    for (auto c : s)
    {
        sum += c - '0';
    }
    return sum;
}

void printSum(int n)
{
    static unordered_map<int, string> table = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}};
    stack<int> s;
    do
    {
        s.push(n % 10);
        n /= 10;
    } while (n > 0);
    while (s.size() != 1)
    {
        cout << table[s.top()] << ' ';
        s.pop();
    }
    cout << table[s.top()];
    s.pop();
}

int main()
{
    string s;
    cin >> s;
    auto sum = computeSum(s);
    printSum(sum);
    return 0;
}