#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> N >> M;

    vector<string> board(N);

    for (int i = 0; i < N; i++)
        cin >> board[i];

    int cnt = 100;
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int cntW = 0;
            int cntB = 0;

            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    if ((x + y) % 2 == 0)
                    {
                        if (board[i + x][j + y] != 'W')
                            cntW++;
                        if (board[i + x][j + y] != 'B')
                            cntB++;
                    }
                    else
                    {
                        if (board[i + x][j + y] != 'W')
                            cntB++;
                        if (board[i + x][j + y] != 'B')
                            cntW++;
                    }
                }
            }
            cnt = min(cnt, min(cntW, cntB));
        }
    }

    cout << cnt;
}