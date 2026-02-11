#include <bits/stdc++.h>
using namespace std;


// 26짜리 string 배열 생성
// 5개의 문제
// 
// map? 두개로 접근 빠르게?
// int string을 저장할수 있는 문제 배열?
int main(){
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);

    unordered_map<string, int> pokemonsbystring;
    unordered_map<int, string> pokemonsbyint;
    

    int N, M;
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        pokemonsbyint[i + 1] = s;
        pokemonsbystring[s] = i + 1;
    }

    string q;

    for(int i = 0; i < M; i++){
        cin >> q;
        if(isdigit(q[0]) != 0){ // 첫번째 글짜가 숫자인지 체크
            cout << pokemonsbyint[stoi(q)] << "\n";
        }
        else{
            cout << pokemonsbystring[q] << "\n";
        }
    }
}
