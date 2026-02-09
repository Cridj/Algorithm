#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int E, S, M;
    cin >> E >> S >> M;

    int e = 1, s = 1, m = 1;
    int cnt = 1;
    while (true)
    {
        if (E == e && S == s && M == m)
            break;
        e++;
        s++;
        m++;

        if (e > 15)
            e = 1;
        if (s > 28)
            s = 1;
        if (m > 19)
            m = 1;
        cnt++;
    }
    cout << cnt;
    return 0;
}