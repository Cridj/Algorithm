class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i = 0; i <= n; i++)
        {
            unsigned int q = i;
            v.push_back(std::popcount(q));
        }
        return v;
    }
};