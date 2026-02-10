#include <bits/stdc++.h>
using namespace std;

int main(){
    cout.tie(0);
    cin.tie(0);
    string s;
    getline(cin, s);

    for(auto &c : s){
        if(islower(c))
            c = 'a' + (c - 'a' + 13) % 26;
        if(isupper(c))
            c = 'A' + (c - 'A' + 13) % 26;
    }
    cout << s;
}