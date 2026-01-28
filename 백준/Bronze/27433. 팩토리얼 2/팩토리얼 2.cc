#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    long long total = 1;
    for(int i = N; i > 0; i--)
        total *= i;
    cout << total;

    return 0;
}