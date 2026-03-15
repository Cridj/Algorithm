#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(0);
    string a,b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if(stoi(a) > stoi(b))
        cout << a;
    else
    cout << b;
}