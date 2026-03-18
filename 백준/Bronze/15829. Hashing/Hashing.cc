#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L;
    cin >> L;

    string s;
    cin >> s;

    const long long M = 1234567891;
    const long long r = 31;

    long long sum = 0;
    long long powR = 1; // 31^0

    for (int i = 0; i < L; i++)
    {
        long long value = s[i] - 'a' + 1;
        sum = (sum + value * powR) % M;
        powR = (powR * r) % M;
    }

    cout << sum;
}