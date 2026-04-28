#include <bits/stdc++.h>

using namespace std;

bool dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& route)
{
    route.push_back(cur);    
    
    if(route.size() == tickets.size() + 1)
        return true;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(!visited[i] && tickets[i][0] == cur)
        {
            visited[i] = true;
            if(dfs(tickets[i][1], tickets, visited, route))
                return true;
            visited[i] = false;
        }
    }
    route.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    vector<bool> visited(tickets.size(), false);
    
    dfs("ICN", tickets, visited, answer);
    return answer;
}