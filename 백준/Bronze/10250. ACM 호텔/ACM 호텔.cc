#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, H, W, N;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;

        int floor = (N - 1) % H + 1;
        int room = (N - 1) / H + 1;

        cout << floor * 100 + room << endl;
    }
}