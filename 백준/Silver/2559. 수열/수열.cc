#include <bits/stdc++.h>
using namespace std;


// N 전체 날자 2 <= N <= 100000 K  입력 -100 <= K <= 100 
// iter 
int main(){
    cout.tie(0);
    cin.tie(0);

    int N, K;
    cin >> N; cin >> K;

    vector<int> nums;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }

    int tempSum;
    int maxSum = -9999999999;
    for(int i = 0; i < N - K + 1; i++)
    {
        tempSum = 0;
        auto iter = nums.begin() + i;

        for(int n = 0; n < K; n++){
            tempSum += iter[n];
        }
        maxSum = max(tempSum, maxSum);
    }
    cout << maxSum;
}