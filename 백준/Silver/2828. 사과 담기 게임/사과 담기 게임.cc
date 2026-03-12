#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(true);
    cin.tie(NULL);

    int N,M,J;
    cin >> N >> M;
    cin >> J;

    vector<int> points;
    for(int i = 0; i < J; i++)
    {
        int p;
        cin >> p;
        points.push_back(p - 1);
    }
    int cur_pos = 0;

    int sum = 0;
    for(auto p : points)
    {
        int left = cur_pos; // 현재 바구니 시작
        int right = cur_pos + M - 1; // 바구니 범위 끝

        //바구니 범위 안일때는 그냥 가만히있기
        if(p < left)
        {
            sum += left - p;
            cur_pos = p;
        }
        else if(p > right)
        {
            int move = p - right;
            sum += move;
            cur_pos += move;
        }
    }
    cout << sum;
}