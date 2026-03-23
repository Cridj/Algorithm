#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    cout << factorial(N);

    return 0;
}

