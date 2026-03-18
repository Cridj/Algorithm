#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, T, P;
    int size[6];
    cin >> N;
    for(int i = 0; i < 6; i++)
    {
        int cnt;
        cin >> cnt;
        size[i] = cnt;
    }
    cin >> T >> P;

    int t_cnt = 0, p_cnt = 0;
    for(int i = 0; i < 6; i++)
    {
        t_cnt +=  size[i] / T + 1;
        if(size[i] % T == 0)
            t_cnt--;
    }


    cout << t_cnt << "\n" << N / P << " " << N % P;
}