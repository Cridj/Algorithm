#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Pos
{
    int y;
    int x;
};

struct PathData
{
    bool isSuccess = false;
    Pos pos;
    vector<Pos> eatFishes;
    int routeSize = 0;
};

// 먹을 물고기가 있는지 체크
// 물고기가 여러마리라면 거리가 가장 가까운 물고기
// 거리가 가까운 물고기가 여러마리라면 가장 Y축이 낮은 물고기
// 그런 물고가기 여러마리라면 가장 왼쪽에 있는 물고기로 목표 설정
// 도달중에 경로상에 있는 물고기 섭취 가능
// 실제로 갈 수 있는지 체크,

PathData isValidPath(Pos s, Pos e, int &sharkSize)
{
    PathData data;
    visited.assign(N, vector<int>(N, -1));
    queue<Pos> q;
    q.push(s);
    visited[s.y][s.x] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.y == e.y && cur.x == e.x)
        {
            data.pos = e;
            data.routeSize = visited[e.y][e.x];
            data.isSuccess = true;
            return data;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (adj[ny][nx] <= sharkSize && visited[ny][nx] == -1)
            {
                if (adj[ny][nx] > 0)
                    data.eatFishes.push_back({ny, nx});
                visited[ny][nx] = visited[cur.y][cur.x] + 1;
                q.push({ny, nx});
            }
        }
    }
    data.isSuccess = false;
    return data;
}

vector<Pos> getValidFishPos(int size)
{
    vector<Pos> validPath;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (adj[y][x] > 0 && adj[y][x] < size)
                validPath.push_back({y, x});
    return validPath;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    adj.assign(N, vector<int>(N));

    Pos curPos;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> adj[y][x];
            if (adj[y][x] == 9)
            {
                adj[y][x] = 0;
                curPos.y = y;
                curPos.x = x;
            }
        }
    }
    int sharkSize = 2;
    int eatCnt = 0;
    int time = 0;
    vector<Pos> validV;
    // 일단 모든 배열에 현재 먹을수 있는 물고기가 있는지
    while (true)
    {
        vector<PathData> paths;
        validV = getValidFishPos(sharkSize);
        
        if (validV.size() == 0) // 먹을수 있는 물고기가 없으면 종료
            break;
        // 만약 먹을수 있는 물고기가 있다면 경로가 유효한지 체크
        for (int i = 0; i < validV.size(); i++)
        {
            PathData path = isValidPath(curPos, validV[i], sharkSize);
            if (path.isSuccess == true)
                paths.push_back(path);
        }
        if(paths.empty())
            break;
        sort(paths.begin(), paths.end(), [](const PathData &a, const PathData &b) 
        {
            if(a.routeSize != b.routeSize)
                return a.routeSize < b.routeSize;
            if(a.pos.y != b.pos.y)
                return a.pos.y < b.pos.y;           
            return a.pos.x < b.pos.x;
        });
        // 경로가 유효한 물고기가 여러마리 있다면 가장 가까운 / 가장 높은 / 가장 왼쪽
        PathData target = paths[0];
        time += target.routeSize;
        curPos = target.pos;
        eatCnt ++;
        adj[curPos.y][curPos.x] = 0;

        if(eatCnt == sharkSize)
        {
            sharkSize++;
            eatCnt = 0;
        }
 
        // 순으로 설정하여 가장 우선순위가 높은 물고기를 타겟으로 삼고 최단경로 계산
    }
    cout << time;
}