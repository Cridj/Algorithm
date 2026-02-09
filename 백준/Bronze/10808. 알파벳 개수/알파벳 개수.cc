#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    char alphabet = 'a';

    for(int i = 0; i < 26; i++){
        int cnt = count(s.begin(),s.end(), alphabet + i);
        cout << cnt << " ";
    }
    return 0;
}