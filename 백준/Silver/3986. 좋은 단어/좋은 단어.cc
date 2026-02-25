#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int N, cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        stack<char> st;

        for (auto c : s)
        {
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        if (st.empty())
            cnt++;
    }
    cout << cnt;

}