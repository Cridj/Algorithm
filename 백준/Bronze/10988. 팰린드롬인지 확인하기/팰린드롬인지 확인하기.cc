#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (s.compare(s1))
        cout << 0;
    else
        cout << 1;

    return 0;
}