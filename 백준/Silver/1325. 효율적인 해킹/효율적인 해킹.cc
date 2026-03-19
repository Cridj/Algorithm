#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int n, int& cnt)
{
    cnt++;
    visited[n] = true;

    for(int i = 0; i < adj[n].size(); i++)
    {
        if(!visited[adj[n][i]])
            dfs(adj[n][i], cnt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    adj.assign(N, vector<int>());
    map<int, vector<int>> m;
    for(int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        //b - > a
        adj[b].push_back(a);
    }

    
    for(int i = 0; i < N; i++)
    {
        visited.assign(N, false);
        int cnt = 0;
        dfs(i, cnt);
        m[cnt].push_back(i);
    }
    auto it = prev(m.end());
    for(auto n : it->second)   
    {
        cout << n + 1 << " ";
    }
}