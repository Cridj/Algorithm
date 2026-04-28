#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<bool> visited;

void bfs(int start, int n)
{
    queue<int> q;
    q.push(start);     
    visited[start] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && board[cur][i] == 1)
            {
                visited[i] = true;                
                q.push(i);
            }       
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;  
    board = computers;
    visited.assign(n, false);
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bfs(i, n);
            answer++;
        }
    }
    
    return answer;
}