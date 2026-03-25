#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int R, C;
queue<pair<int, int>> fire;

void spread_fire()
{
    int size = fire.size();

    for(int i = 0; i < size; i++)
    {
        auto cur = fire.front();
        fire.pop();

        int y = cur.first;
        int x = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;
            if (board[ny][nx] == 0)
            {
                board[ny][nx] = -1;
                fire.push({ny, nx});
            }
        }
    }
}

void simulate(pair<int, int> start)
{
    queue<pair<int, int>> q;
    visited[start.first][start.second] = 0;

    q.push(start);
    while (!q.empty())
    {
        int q_size = q.size();
        spread_fire();

        for (int n = 0; n < q_size; n++)
        {
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                {
                    cout << visited[y][x] + 1;
                    return;
                }

                if (visited[ny][nx] == -1 && board[ny][nx] == 0)
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;

    pair<int, int> start;
    board.assign(R, vector<int>(C));
    visited.assign(R, vector<int>(C, -1));
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int n = 0; n < s.size(); n++)
        {
            if (s[n] == '#')
            {
                board[i][n] = -1;
            }
            else if (s[n] == 'F')
            {
                board[i][n] = 2;
                fire.push({i, n});
            }
            else if (s[n] == 'J')
            {
                start = {i, n};
                board[i][n] = 0;
            }
            else
                board[i][n] = 0;
        }
    }

    simulate(start);
}