#include <bits/stdc++.h>
using namespace std;

// 테스트 케이스 입력
// string 순회하며 카운트배열 map[char] 에 저장?
// 만약 문자열 길이가 홀수일때는 1개의 홀수가 존재 가능, 길이가 짝수일때는 모든 문자의 개수가 짝수이어야 함

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);

    map<char, int> count;
    string a, str, temp, mid = "";
    int oddCount = 0;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
        count[a[i]]++;

    if (a.length() % 2 == 0) // 짝수일때
    {
        for (auto i : count)
        {
            if (i.second % 2 == 1)
                oddCount++;
            for (int n = 0; n < i.second / 2; n++)
                temp += i.first;
        }
    }
    else // 홀수일때
    {
        for (auto i : count)
        {
            if (i.second % 2 == 1)
            {
                oddCount++;
                mid = i.first;
            }
            for (int n = 0; n < i.second / 2; n++)
                temp += i.first;
        }
    }
    str += temp;
    str += mid;
    reverse(temp.begin(), temp.end());
    str += temp;

    if (oddCount > 1 || str.size() == 0)
        cout << "I'm Sorry Hansoo";
    else
        cout << str;
}
