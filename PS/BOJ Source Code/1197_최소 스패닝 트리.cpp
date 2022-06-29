#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#include <memory.h>

using namespace std;

struct cmp
{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
    {
        return a.second > b.second;
    }
};

int union_find[10001];

int v, e;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;

int find(int x)
{
    if (union_find[x] == x)
        return x;
    return union_find[x] = find(union_find[x]);
}

void union_set(int x, int y)
{
    union_find[find(y)] = find(x);
    return;
}

int main()
{
    scanf("%d %d", &v, &e);
    int ans = 0;
    for (int i = 0; i < e; i++)
    {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        pq.push({{from, to}, w});
    }
    for (int i = 1; i <= v; i++)
        union_find[i] = i;
    int cnt = 0;
    while (cnt < v - 1)
    {
        pair<pair<int, int>, int> min_edge = pq.top();
        pq.pop();
        int from = min_edge.first.first;
        int to = min_edge.first.second;
        int w = min_edge.second;
        if (find(from) != find(to))
        {
            ans += w;
            union_set(from, to);
            cnt++;
        }
    }
    cout << ans;
}