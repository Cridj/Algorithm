#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if(a == 1)
            continue;
            
        bool isPrime = true;

        for (int j = 2; j < a; j++)
        {
            if (a % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            cnt++;
    }
    cout << cnt;
}