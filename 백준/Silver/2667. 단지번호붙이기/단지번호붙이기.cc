#include <bits/stdc++.h>
using namespace std;
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

vector<vector<int>> adj;
vector<vector<bool>> visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N = 0;

void visit(int y, int x, int num, int& cnt)
{
    visited[y][x] = true;
    adj[y][x] = num;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (adj[ny][nx] >= 1 && !visited[ny][nx]) // 가능한 경로이고 방문한적 없다면
            visit(ny, nx, num, cnt);
    }
}

int main()
{
    cin >> N;
    adj.assign(N, vector<int>(N));
    visited.assign(N, vector<bool>(N, false));
    for (int y = 0; y < N; y++)
    {
        string s;
        cin >> s;
        for(int x = 0; x < N; x++)
            adj[y][x] = s[x] - '0';
    }

    int componentCnt = 0;
    vector<int> cnts;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (adj[y][x] >= 1 && !visited[y][x])
            {
                componentCnt++;
                int cnt = 0;
                visit(y, x, componentCnt + 1, cnt);
                cnts.push_back(cnt);
            }
        }
    }
    cout << componentCnt << "\n";
    sort(cnts.begin(), cnts.end());
    for(int i = 0; i < cnts.size(); i++)
    {
        cout << cnts[i] << "\n";
    }
    return 0;
}
