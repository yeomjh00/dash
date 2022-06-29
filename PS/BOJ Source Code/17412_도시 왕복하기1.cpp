#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#include <memory.h>

using namespace std;

int v, e;
int adj_mat[401][401];
int visit[401];

void reset_visit()
{
    visit[1] = 1;
    memset(visit, 0, sizeof(visit));
}

bool dfs(int par, int cur, int end)
{
    bool arrive = false;
    // We already know end point is 2.
    if (cur == end)
        return visit[end] = par;
    for (int i = 1; i <= v; i++)
    {
        if (!adj_mat[cur][i])
            continue;
        int next = i;
        if (!visit[next])
        {
            visit[next] = cur;
            arrive = (arrive || dfs(cur, next, end));
        }
    }
    return arrive;
}

int max_flow(int start, int end)
{
    int cnt = 0;
    while (dfs(start, start, end))
    {

        for (int i = 2; i != start; i = visit[i])
        {
            adj_mat[visit[i]][i] = 0;
            adj_mat[i][visit[i]] = 1;
        }
        reset_visit();
        cnt++;
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        adj_mat[from][to] = 1;
    }
    cout << max_flow(1, 2);
}