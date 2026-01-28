#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    int a = 0;
    cin >> a;
    vector<int> v;
    for(int i = 0; i < a; i++) {
        v.push_back(i + 1);
    }
    sort(v.begin(), v.end());    
    do{
        for(int i : v) 
            cout << i << " ";
        cout << "\n";
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}