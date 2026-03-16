#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> board;
vector<vector<int>> visited; // 0 : 미방문, 1 : 현재 사이클 도는 중, 2 : 방문 완료


void dfs(int y, int x, int& cnt)
{
    visited[y][x] = 1;

    auto dir = board[y][x];
    int next_y = y + dir.first;
    int next_x = x + dir.second;

    if(visited[next_y][next_x] == 0)
    {
        dfs(next_y, next_x, cnt);
    }
    else if(visited[next_y][next_x] == 1)
        cnt++;
    visited[y][x] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 순환하는게 있다면 + 1
    // 서로 바라보는게 있다면 + 1
    cin >> N >> M;

    board.assign(N, vector<pair<int, int>>(M));
    visited.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int n = 0; n < s.size(); n++)
        {
            switch (s[n])
            {
                case 'U':
                    board[i][n] = {-1, 0};
                break;
                case 'D':
                    board[i][n] = {1, 0};
                break;          
                case 'L':
                    board[i][n] = {0, -1};
                break;         
                case 'R':
                    board[i][n] = {0, 1};
                break;
            }
        }
    }

    int cnt = 0;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            if(!visited[y][x])
            {
                dfs(y, x, cnt);
            }
        }
    }

    cout << cnt;
}