#include <bits/stdc++.h>
using namespace std;

bool check_vowels(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        bool success = true;
        bool include_vowels = false;
        int vowels_cnt = 0;
        int consonant_cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i != 0 && s[i] == s[i - 1])
            {
                if (s[i] != 'e' && s[i] != 'o')
                {
                    success = false;
                    break;
                }
            }
            if (check_vowels(s[i]))
            {
                vowels_cnt++;
                consonant_cnt = 0;
                if (vowels_cnt == 3)
                {
                    success = false;
                    break;
                }
                include_vowels = true;
            }
            else
            {
                consonant_cnt++;
                vowels_cnt = 0;
                if (consonant_cnt == 3)
                {
                    success = false;
                    break;
                }
            }
        }
        if(!include_vowels)
            success = false;
        if (success)
            cout << "<" << s << "> is acceptable.";
        else
            cout << "<" << s << "> is not acceptable.";
        cout << "\n";
    }
}