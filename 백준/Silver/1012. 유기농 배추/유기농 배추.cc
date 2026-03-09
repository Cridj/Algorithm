#include <bits/stdc++.h>
using namespace std;
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

vector<vector<bool>> adj;
vector<vector<bool>> visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int T, M, N, K = 0;

void visit(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (adj[ny][nx] == true && !visited[ny][nx])
            visit(ny, nx);
    }
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        adj.assign(N, vector<bool>(M, false));
        visited.assign(N, vector<bool>(M, false));
        for (int i = 0; i < K; i++)
        {
            int x, y = 0;
            cin >> x >> y;
            adj[y][x] = true;
        }

        int cnt = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (adj[y][x] == true && !visited[y][x])
                {
                    cnt++;
                    visit(y, x);
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}