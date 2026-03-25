#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<char> ops;
int result = INT_MIN;

int calc(int a, int b, char op)
{
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

void dfs(int idx, int cur)
{
    if(idx == ops.size())
    {
        result = max(result, cur);
        return;
    }

    //그냥 바로 계산
    int no_group = calc(cur, nums[idx + 1], ops[idx]);
    dfs(idx + 1, no_group);

    //다음꺼랑 괄호묶어서 연산
    if(idx + 1 < ops.size()) //범위 체크
    {
        int group = calc(nums[idx + 1], nums[idx + 2], ops[idx + 1]);
        int sum = calc(cur, group, ops[idx]);
        dfs(idx + 2, sum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        if(i % 2 == 0) nums.push_back(s[i] - '0');
        else ops.push_back(s[i]);
    }

    dfs(0, nums[0]);
    cout << result;
}