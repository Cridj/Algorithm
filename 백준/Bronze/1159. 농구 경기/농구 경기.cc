#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    map<char, int> v;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        v[s[0]]++;
    }

    vector<char> s;

    for(auto iter = v.begin(); iter!= v.end(); ++iter){
        if(iter->second >= 5)
            s.push_back(iter->first);
    }


    for(auto value : s){
        cout << value;
    }

    if(s.size() == 0){
        cout << "PREDAJA";
    }

    return 0;
}