#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> visited;
vector<pair<int, int>> v;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int bfs(pair<int, int> start)
{
    visited.assign(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    visited[start.first][start.second] = 1;
    int max_length = 0;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int y = cur.first;
        int x = cur.second;
        max_length = max(max_length, visited[y][x]);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (!visited[ny][nx] && board[ny][nx] == 1)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return max_length - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    board.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M, 0));

    for (int y = 0; y < N; y++)
    {
        string s;
        cin >> s;
        for (int x = 0; x < s.size(); x++)
        {
            if (s[x] == 'W')
            {
                board[y][x] = 0;
            }
            else if (s[x] == 'L')
            {
                board[y][x] = 1;
                v.push_back({y, x});
            }
        }
    }

    int path_length = 0;
    for (auto l : v)
    {
        path_length = max(path_length, bfs(l));
    }
    cout << path_length;
    return 0;
}