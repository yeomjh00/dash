#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#include <memory.h>

using namespace std;

// Adjacency list를 쓴다면, 기억해야할 것!
// Bellman Ford는 V-1 iteration동안 each iteration마다, 모든 Edge를 돌아다니므로,
// Adjacency list를 쓴다면, 3중 for문이 나와야한다.

int v, e;
vector<vector<pair<int, int>>> adj_list;
long long dist[501];

int main()
{
    scanf("%d %d", &v, &e);
    adj_list.resize(v + 2);

    // input of adjacency list
    for (int i = 0; i < e; i++)
    {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        adj_list[from].push_back(make_pair(to, w));
    }
    // initializing
    for (int i = 0; i <= 500; i++)
        dist[i] = 987654321;
    dist[1] = 0;
    bool negcycle = false;

    for (int l = 1; l <= v; l++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 0; j < adj_list[i].size(); j++)
            {
                if (dist[i] != 987654321)
                {
                    if (dist[i] + adj_list[i][j].second < dist[adj_list[i][j].first])
                    {
                        dist[adj_list[i][j].first] = dist[i] + adj_list[i][j].second;
                        if (l == v)
                            negcycle = true;
                    }
                }
            }
        }
    }

    if (negcycle)
        cout << "-1";
    else
    {
        for (int i = 2; i <= v; i++)
        {
            if (dist[i] != 987654321)
                cout << dist[i] << "\n";
            else
                cout << "-1\n";
        }
    }
}