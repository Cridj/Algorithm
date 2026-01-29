#include <bits/stdc++.h>
using namespace std;

vector<int> heights;
vector<int> results;

void findDwarfs(int idx, int currentSum, vector<int> &currentHeights){
    if(currentHeights.size() > 7)
        return;
    
    if(currentHeights.size() == 7){
        if(currentSum == 100){
            results = currentHeights;
        }      
        return;
    }

    for(int i = idx; i < 9; i++){
            currentHeights.push_back(heights[i]);
            findDwarfs(i + 1, currentSum + heights[i], currentHeights);
            currentHeights.pop_back();
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

 
    for(int i = 0; i < 9; i++){
        int height;
        cin >> height;
        heights.push_back(height);
    }

    vector<int> currentHeights;
    findDwarfs(0,0,currentHeights);
    
    sort(results.begin(), results.end());
    
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << "\n";
    }
    return 0;
}