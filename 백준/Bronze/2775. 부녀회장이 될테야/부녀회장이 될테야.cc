#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        int k, n;
        cin >> k >> n;

        int apt[15][15] = {0};

        for(int i = 1; i <= n; i++)
            apt[0][i] = i;

            for(int i = 1; i <= k; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
                }
            }
        cout << apt[k][n] << "\n";
    }
}