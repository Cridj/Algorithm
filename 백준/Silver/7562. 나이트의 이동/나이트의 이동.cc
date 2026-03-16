#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};


int bfs(vector<vector<int>>& visited, pair<int, int> start, pair<int, int> end)
{
    visited[start.first][start.second] = 0;
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(cur.first == end.first && cur.second == end.second)
            return visited[end.first][end.second];
        
        for(int i = 0; i < 8; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if(ny < 0 || ny >= visited.size() || nx < 0 || nx >= visited.size())
                continue;

            if(visited[ny][nx] < 1)
            {
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.push({ny,nx});
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int length;
        pair<int,int> start, end;
        cin >> length;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;


        vector<vector<int>> visited;
        visited.assign(length, vector<int>(length, 0));
        cout << bfs(visited, start, end) << "\n";
    }
}