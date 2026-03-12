#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, C;
    cin >> N >>  C;

    vector<int> arr(N);
    map<int, int> cnts;
    map<int, int> order;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        cnts[arr[i]]++;

        if(order.count(arr[i]) == 0)
            order[arr[i]] = i;
    }

    sort(arr.begin(), arr.end(), [&](int a, int b)
        {
            if(cnts[a] != cnts[b])
                return cnts[a] > cnts[b];
            return order[a] < order[b];
        });
    
    for(auto c : arr)
        cout << c << " ";
}