#include <bits/stdc++.h>
using namespace std;

int N, L, R;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

vector<pair<int, int>> check(pair<int, int> start)
{
    vector<pair<int, int>> cur_list;
    queue<pair<int, int>> q;
    visited[start.first][start.second] = true;
    q.push(start);
    cur_list.push_back(start);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int y = cur.first;
        int x = cur.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            int n = abs(board[ny][nx] - board[y][x]);
            if (!visited[ny][nx] && n >= L && n <= R)
            {
                visited[ny][nx] = true;
                cur_list.push_back({ny, nx});
                q.push({ny, nx});
            }
        }
    }
    return cur_list;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> R;
    board.assign(N, vector<int>(N));
    visited.assign(N, vector<bool>(N, false));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }
    int cnt = 0;
    while (true)
    {
        bool clear = false;
        visited.assign(N, vector<bool>(N, false));
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (!visited[y][x])
                {
                    auto li = check({y, x});
                    if(li.size() > 1)
                        clear = true;
                    int sum = 0;
                    for (auto e : li)
                    {
                        sum += board[e.first][e.second];
                    }
                    for (auto e : li)
                    {
                        board[e.first][e.second] = sum / li.size();
                    }
                }
            }
        }

        if(clear == false)
            break;
        else
            cnt++;            
    }
    cout << cnt;
}