#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int sum = 0;
    for(auto c : s)
    {
        if(c <= 'C') sum += 3;
        else if(c <= 'F') sum += 4;
        else if(c <= 'I') sum += 5;
        else if(c <= 'L') sum += 6;
        else if(c <= 'O') sum += 7;
        else if(c <= 'S') sum += 8;
        else if(c <= 'V') sum += 9;
        else sum += 10;
    }
    cout << sum;
}