#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> numbers;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        string a;
        for (int n = 0; n < s.size(); n++)
        {
            if (isdigit(s[n])) // 숫자일때
                a.push_back(s[n]);
            else
            {
                if (!a.empty())
                {
                    while (a.size() > 1 && a[0] == '0')
                        a.erase(a.begin());
                    numbers.push_back(a);
                    a.clear();
                }
            }
        }
        if (!a.empty())
        {
            while (a.size() > 1 && a[0] == '0')
                a.erase(a.begin());
            numbers.push_back(a);
        }
    }
    sort(numbers.begin(), numbers.end(), [](string &a, string &b) 
    {
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;            
    });
    for (auto n : numbers)
        cout << n << "\n";
}
