#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};


int bfs(int n, int m)
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty())
    {
        auto [y,x] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if(visited[ny][nx] == -1 && board[ny][nx] == 1)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    
    return visited[n-1][m-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    board = maps;
    
    int n = maps.size();
    int m = maps[0].size();
    visited.assign(n, vector<int>(m, -1));
    
    answer = bfs(n, m);
    return answer;
}