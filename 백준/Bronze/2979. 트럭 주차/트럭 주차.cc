#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int A, B, C;
    cin >> A >> B >> C;
    vector<vector<bool>> costs;
    for (int i = 0; i < 3; i++)
    {
        int start, end;
        cin >> start >> end;
        vector<bool> current(100, false);
        for (int i = start - 1; i < end - 1; i++)
        {
            current[i] = true;
        }
        costs.push_back(current);
    }

    int sum = 0;

    for (int n = 0; n < 100; n++)
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            if (costs[i][n])
                count++;
        }
        if (count == 1)
            sum += A;
        else if (count == 2)
            sum += B * 2;
        else if (count == 3)
            sum += C * 3;
    }
    cout << sum;

    return 0;
}