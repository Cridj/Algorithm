#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<vector<int>> adj(1001);
vector<bool> visited(1001);
vector<int> letD;
vector<int> letB;
void dfs(int start)
{
    letD.push_back(start);
    visited[start] = true;
    for (int next : adj[start])
    {
        if (!visited[next])
            dfs(next);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        letB.push_back(cur);

        for (int next : adj[cur])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    for(int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(V);
    visited.assign(1001,false);
    bfs(V);

    for(int i = 0; i < letD.size(); i++)
        cout << letD[i] << " ";
    cout << "\n";
    for(int i = 0; i < letB.size(); i++)
        cout << letB[i] << " ";

    return 0;
}