#include <bits/stdc++.h>
using namespace std;

int cnt;  // recursion 호출 횟수
int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) 
    {
        string s;
        cin >> s;

        cnt = 0;
        int result = isPalindrome(s.c_str());
        cout << result << " " << cnt << "\n";
    }
}