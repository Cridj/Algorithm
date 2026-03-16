#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<vector<int>>> visited;

int N, M;
int dy[]{0, 1, 0, -1};
int dx[]{-1, 0, 1, 0};

int bfs(pair<int, int> end)
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int broke = get<2>(cur);

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            int nbroke = broke;

            if (board[ny][nx] == 1)
            {
                if (nbroke >= 1)
                    continue;
                nbroke = 1;
            }

            if (visited[ny][nx][nbroke] == 0)
            {
                visited[ny][nx][nbroke] = visited[y][x][broke] + 1;
                q.push({ny, nx, nbroke});
            }
        }
    }

    int a = visited[end.first][end.second][0];
    int b = visited[end.first][end.second][1];

    if(a == 0 && b == 0) return -1;
    if(a == 0) return b;
    if(b == 0) return a;
    return min(a,b);    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<vector<int>>(M, vector<int>(2, 0)));

    for (int y = 0; y < N; y++)
    {
        string s;
        cin >> s;
        for (int x = 0; x < s.size(); x++)
        {
            board[y][x] = s[x] - '0';
        }
    }
    cout << bfs({N - 1, M - 1});
}