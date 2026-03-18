#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt = 1, end = 1;
    while (N > end)
    {
        end += 6 * cnt;
        cnt++;
    }
    cout << cnt;
}