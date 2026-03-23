#include <bits/stdc++.h>
using namespace std;

int N, M;
int min_distance = INT_MAX;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int,int>> survived_chicken;

int check_distance()
{
    int sum = 0;
    for(auto h : house)
    {
        int distance = INT_MAX;
        for(auto c : survived_chicken)
        {
            distance = min(distance, abs(h.first - c.first) + abs(h.second - c.second));
        }
        sum += distance;
    }
    return sum;
}

void select_chicken(int idx)
{
    if(survived_chicken.size() == M)
    {
        min_distance = min(min_distance, check_distance());
        return;
    }

    for(int i = idx; i < chicken.size(); i++)
    {
        survived_chicken.push_back(chicken[i]);
        select_chicken(i + 1);
        survived_chicken.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            int n;
            cin >> n;
            if (n == 1)
                house.push_back({y, x});
            else if (n == 2)
                chicken.push_back({y, x});
        }
    }
    select_chicken(0);
    cout << min_distance;
}