#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b)
{
    int dif = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) dif++;
    }
    return dif == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    map<string, int> visited;
    queue<string> q;
    q.push(begin);
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        if(cur == target)
            return visited[target] + 1;
        
        for(int i = 0; i < words.size(); i++)
        {
            if(visited[words[i]] == 0 && check(cur, words[i]))
            {
                if(cur == begin)
                    visited[cur] = 2;
                else
                    visited[words[i]] = visited[cur] + 1;
                q.push(words[i]);
            }              
        }
    }
    return answer;
}