#include <bits/stdc++.h>
using namespace std;

int N;
int hp[3];
int visited[61][61][61];

int damage[6][3] =
{
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9},
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> hp[i];

    queue<tuple<int,int,int>> q;

    q.push({hp[0], hp[1], hp[2]});
    visited[hp[0]][hp[1]][hp[2]] = 1;


    while(!q.empty())
    {
        auto cur = q.front();
        int a = get<0>(cur);
        int b = get<1>(cur);
        int c = get<2>(cur);
        q.pop();

        if(a == 0 && b == 0 && c == 0)
        {
            cout << visited[a][b][c] - 1;
            return 0;
        }
        for(int i = 0; i < 6; i++)
        {
            int na = max(0, a - damage[i][0]);
            int nb = max(0, b - damage[i][1]);
            int nc = max(0, c - damage[i][2]);

            if(visited[na][nb][nc] == 0)
            {
                visited[na][nb][nc] = visited[a][b][c] + 1;
                q.push({na,nb,nc});
            }
        }
    }
}