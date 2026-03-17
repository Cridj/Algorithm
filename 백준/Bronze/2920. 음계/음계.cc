#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(8);
    for (int i = 0; i < 8; i++)
        cin >> v[i];

    if (v == vector<int>{1,2,3,4,5,6,7,8})
        cout << "ascending";
    else if (v == vector<int>{8,7,6,5,4,3,2,1})
        cout << "descending";
    else
        cout << "mixed";
}