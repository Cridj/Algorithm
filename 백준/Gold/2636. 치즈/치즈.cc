#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pair<int, int>> melt;
int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (visited[ny][nx])
            continue;

        if (board[ny][nx] == 0)
        {
            dfs(ny, nx);
        }
        else if(board[ny][nx] == 1)
        {
            visited[ny][nx] = true;
            melt.push_back({ny, nx});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> board[y][x];

    int time = 0;
    int last_cnt = 0;

    while (true)
    {
        visited.assign(N, vector<bool>(M, false));
        melt.clear();
        dfs(0, 0);
        if(melt.empty())
            break;
        
        last_cnt = melt.size();

        for(auto p : melt)
            board[p.first][p.second] = 0;
        
        time++;
    }

    cout << time << "\n" << last_cnt;

}