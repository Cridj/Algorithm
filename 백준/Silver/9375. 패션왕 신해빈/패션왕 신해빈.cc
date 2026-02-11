#include <bits/stdc++.h>
using namespace std;

//테스트 케이스 입력
//테스크 케이스 기반 순회 후 의상 추가 입력
int main()
{
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int cnt = 0;
        cin >> cnt;
        map<string, int> clothes;
        for(int i = 0; i < cnt; i++){
            string cloth, type;
            cin >> cloth >> type;
            clothes[type]++;;
        }

        int result = 1;
        for(auto &c : clothes){
            result *= c.second + 1;
        }
        cout << result - 1 << "\n";
    }
}