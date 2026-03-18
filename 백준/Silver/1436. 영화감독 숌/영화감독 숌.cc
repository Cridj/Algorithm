#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s; 
    int cnt = 0;   
    for(int i = 0; i < 100000000; i++)
    {
        s = to_string(i);

        if(s.find("666") != string::npos)
            cnt++;
        if(cnt == N)
        {
            cout << i;
            break;
        }
    }
    return 0;
}