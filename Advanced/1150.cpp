#include <bits/stdc++.h>

using namespace std;

auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

int main()
{
    int N, M;
    cin >> N >> M;
    unordered_map<int, unordered_map<int, int>> graph;
    for (auto i = 0; i < M; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x][y] = d;
        graph[y][x] = d;
    }
    int K;
    cin >> K;
    int index1 = -1;
    int dist1 = -1;
    int index2 = -1;
    int dist2 = -1;
    for (auto i = 0; i < K; i++)
    {
        int num;
        cin >> num;
        vector<int> point(num);
        vector<bool> visit(N + 1, false);
        for (auto j = 0; j < num; j++)
        {
            cin >> point[j];
            visit[point[j]] = true;
        }
        int distance = 0;
        bool flag = false;
        for (auto j = 0; j < num - 1; j++)
        {
            if (graph[point[j]].count(point[j + 1]) == 0)
            {
                flag = true;
                break;
            }
            distance += graph[point[j]][point[j + 1]];
        }
        if (flag)
        {
            cout << "Path " << i + 1 << ": "
                 << "NA (Not a TS cycle)\n";
        }
        else
        {
            if (point.front() == point.back())
            {
                bool cycle = true;
                for (auto t = 1; t < visit.size(); t++)
                {
                    if (!visit[t])
                    {
                        cycle = false;
                        break;
                    }
                }
                if (cycle)
                {
                    if (N == num - 1)
                    {
                        cout << "Path " << i + 1 << ": " << distance << " (TS simple cycle)\n";
                    }
                    else
                    {
                        cout << "Path " << i + 1 << ": " << distance << " (TS cycle)\n";
                    }
                    if (dist1 == -1)
                    {
                        index1 = i + 1;
                        dist1 = distance;
                    }
                    else if (distance < dist1)
                    {
                        index1 = i + 1;
                        dist1 = distance;
                    }
                }
                else
                {
                    cout << "Path " << i + 1 << ": " << distance << " (Not a TS cycle)\n";
                    if (dist2 == -1)
                    {
                        index2 = i + 1;
                        dist2 = distance;
                    }
                    else if (distance < dist2)
                    {
                        index2 = i + 1;
                        dist2 = distance;
                    }
                }
            }
            else
            {
                cout << "Path " << i + 1 << ": " << distance << " (Not a TS cycle)\n";
                if (dist2 == -1)
                {
                    index2 = i + 1;
                    dist2 = distance;
                }
                else if (distance < dist2)
                {
                    index2 = i + 1;
                    dist2 = distance;
                }
            }
        }
    }
    if (index1 != -1)
    {
        cout << "Shortest Dist(" << index1 << ") = " << dist1 << '\n';
    }
    else
    {
        cout << "Shortest Dist(" << index2 << ") = " << dist2 << '\n';
    }
    return 0;
}