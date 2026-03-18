#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M;
int max_cnt = 0;

int spread_virus()
{
    auto b = board;
    queue<pair<int, int>> q;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] == 2)
            {
                q.push({y, x});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            
            if(b[ny][nx] == 0)
            {
                b[ny][nx] = 2;
                q.push({ny,nx});
            }
        }
    }

    int cnt = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (b[y][x] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void make_wall(int cnt)
{
    if (cnt == 3)
    {
        // 바이러스 퍼트리고
        // 안전영역 계산?
        max_cnt = max(max_cnt, spread_virus());
        return;
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] == 0)
            {
                board[y][x] = 1;
                make_wall(cnt + 1);
                board[y][x] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    board.assign(N, vector<int>(M, 0));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
        }
    }

    make_wall(0);
    cout << max_cnt;
}