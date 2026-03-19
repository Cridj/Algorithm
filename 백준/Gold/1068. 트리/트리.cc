#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int n, int exclude, int& cnt)
{
    visited[n] = true;
    bool leaf = true;

    for(int i = 0; i < adj[n].size(); i++)
    {
        if (visited[adj[n][i]] || adj[n][i] == exclude)
            continue;
        leaf = false;
        dfs(adj[n][i], exclude, cnt);
    }
    if(leaf)
        cnt++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int root;
    cin >> N;
    
    adj.assign(N, vector<int>());
    visited.assign(N, false);
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;

        if(a == -1)
        {
            root = i;
            continue;
        }
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    int n;
    cin >> n;
    if(n == root)
    {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    dfs(root, n, cnt);
    cout << cnt;
}