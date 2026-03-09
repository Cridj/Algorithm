#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N;

void dfs(int y, int x, int height)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (adj[ny][nx] > height && !visited[ny][nx])
            dfs(ny, nx, height);
    }
}

void bfs(int y, int x, int height)
{
    if(visited[y][x] == true)
        return;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || adj[ny][nx] <= height)
                continue;

            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    adj.assign(N, vector<int>(N));

    set<int> heights;
    heights.insert(0);
    for (int i = 0; i < N; i++)
    {
        for (int n = 0; n < N; n++)
        {
            int a;
            cin >> a;
            adj[i][n] = a;
            heights.insert(a);
        }
    }

    int maxCnt = -1;
    // for (auto h : heights) // dfs
    // {
    //     int cnt = 0;
    //     visited.assign(N, vector<bool>(N, false));
    //     for (int y = 0; y < N; y++)
    //     {
    //         for (int x = 0; x < N; x++)
    //         {
    //             if (adj[y][x] > h && !visited[y][x])
    //             {
    //                 cnt++;
    //                 dfs(y, x, h);
    //             }
    //         }
    //     }
    //     maxCnt = max(maxCnt, cnt);
    // }
    for (auto h : heights) // bfs
    {
        int cnt = 0;
        visited.assign(N, vector<bool>(N, false));
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (adj[y][x] > h && !visited[y][x])
                {
                    cnt++;
                    bfs(y, x, h);
                }
            }
        }
        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt;

    return 0;
}