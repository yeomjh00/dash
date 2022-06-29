#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#include <memory.h>

using namespace std;

int v, e;
int dist[101][101];

int main()
{
    scanf("%d %d", &v, &e);
    for (int i = 0; i <= v; i++)
        for (int j = 0; j <= v; j++)
            dist[i][j] = 987654321;
    for (int i = 0; i < e; i++)
    {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        dist[from][to] = min(dist[from][to], w);
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (dist[i][k] == 987654321 && dist[k][j] == 987654321)
                    continue;
                if (i == j)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (dist[i][j] == 987654321)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}