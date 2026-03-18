#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        int left = 0;
        int right = 0;
        int success = true;
        for(auto c : s)
        {
            if(c == '(') left++;
            else
            {
                right++;
                if(right > left)
                {
                    success = false;
                    break;
                }
            }
        }
        if(left == right && success)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}