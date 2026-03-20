#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int sum = 0;
    int starIdx = -1;

    for (int i = 0; i < 13; i++)
    {
        if (s[i] == '*')
        {
            starIdx = i;
            continue;
        }

        int num = s[i] - '0';

        if (i % 2 == 0)
            sum += num;
        else 
            sum += num * 3;
    }

    int need = (10 - (sum % 10)) % 10;

    if (starIdx % 2 == 0)
    {
        cout << need;
    }
    else
    {
        for (int x = 0; x <= 9; x++)
        {
            if ((3 * x) % 10 == need)
            {
                cout << x;
                break;
            }
        }
    }
}