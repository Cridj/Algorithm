#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // 위쪽
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < N - i; j++)
            cout << " ";

        for(int j = 0; j < 2*i - 1; j++)
            cout << "*";

        cout << "\n";
    }

    // 아래쪽
    for(int i = N-1; i >= 1; i--)
    {
        for(int j = 0; j < N - i; j++)
            cout << " ";

        for(int j = 0; j < 2*i - 1; j++)
            cout << "*";

        cout << "\n";
    }
}