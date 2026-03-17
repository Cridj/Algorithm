#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    map<int, int> cnt;

    int sum = 1;
    for(int i = 0; i < 10; i++)
    {
        cnt[i] = 0;
    }
    for(int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        sum *= a;
    }
    for(auto c : to_string(sum))
    {
        cnt[c - '0']++;
    }

    for(auto n : cnt)
    {
        cout << n.second << "\n";
    }
}