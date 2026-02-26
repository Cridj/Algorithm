#include <bits/stdc++.h>
using namespace std;
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int check(int n)
{
    if(n % 2 == 0 || n % 5 == 0)
        return 0;
    if(n == 1)
        return 1;

    int start = 1;
    int length = 1;

    while(start != 0)
    {
        start = (start * 10 + 1) % n;
        length++;
    }

    return length;
}

int main()
{
    FAST_IO

    int n;
    while(cin >> n)
        cout << check(n) << "\n";
}
