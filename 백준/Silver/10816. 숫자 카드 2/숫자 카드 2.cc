#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N, M;
    cin >> N;
    map<int,int> number;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        number[a]++;
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        auto c = number.find(a);
        if(c != number.end())
            cout << c->second << " ";
        else
            cout << 0 << " ";
    }


}