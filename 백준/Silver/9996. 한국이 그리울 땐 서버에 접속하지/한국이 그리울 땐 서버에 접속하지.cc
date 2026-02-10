#include <bits/stdc++.h>
using namespace std;

string condition;
string leftoption; 
string rightoption;

bool checkCondition(string s){
    if(leftoption.size() > s.size() || rightoption.size() > s.size())
        return false;

    if(leftoption.size() + rightoption.size() > s.size())
        return false;
    for(int i = 0; i < leftoption.size(); i++){
        if(leftoption[i] != s[i])
        return false;
    }

    int start = s.size() - rightoption.size();
    for(int i = 0; i < rightoption.size(); i++){
        if(rightoption[i] != s[i + start])
          return false;
    }
    return true;
}

int main(){
    cout.tie(0);
    cin.tie(0);

    int N;
    cin >> N;
    cin >> condition;

    size_t size = condition.find('*');

    leftoption = condition.substr(0, size);
    rightoption = condition.substr(size + 1);


    for(int i = 0; i < N; i++){
        string ss;
        cin >> ss;


        if(checkCondition(ss))
            cout << "DA" << "\n";
        else
            cout << "NE" << "\n";
    }
}