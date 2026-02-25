#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.tie(0);
    cin.tie(0);

    int M,N;
    cin >> N >> M;
    vector<int> s(N);
    for(int i = 0; i < s.size(); i++)
        cin >> s[i];
    
    sort(s.begin(), s.end());

    auto left = s.begin();
    auto right = s.end() - 1;

    int count = 0;
    while(left < right)
    {
        if(*left + *right == M)
        {
            count++;
            ++left;
            --right;
        }
        else if(*left + *right > M)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }

    
    cout << count;
}