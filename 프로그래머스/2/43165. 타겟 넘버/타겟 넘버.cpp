#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> numbers, int target, int depth, int sum)
{
    if(depth == numbers.size())
    {
        if(sum == target)
            return 1;
        else
            return 0;
    }
    
    int a = dfs(numbers, target, depth + 1, sum + numbers[depth]);
    int b = dfs(numbers, target, depth + 1, sum - numbers[depth]);
    
    return a + b;
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, target, 0, 0);
    return answer;
}