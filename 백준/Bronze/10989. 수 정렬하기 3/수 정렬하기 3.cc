#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt[10001] = {0};

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        while (cnt[i]--)
        {
            cout << i << '\n';
        }
    }
}