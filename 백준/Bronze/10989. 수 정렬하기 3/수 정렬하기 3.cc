#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    map<int, int> number;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        number[a]++;
    }

    // sort(number.begin(), number.end());

    for(auto n : number)
    {
        for(int i = 0; i < n.second; i++)
        {
             cout << n.first << "\n";
        }
    }
}