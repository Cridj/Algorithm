#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    while(true)
    {
        string s;
        cin >> s;
        if(s == "0")
            return 0;
        auto temp = s;
        reverse(s.begin(),s.end());

        if(s == temp)
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
    return 0;
}