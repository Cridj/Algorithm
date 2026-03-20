#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n <= 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << fact(n) / (fact(k) * fact(n - k));
}