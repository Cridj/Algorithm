class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = word.size();

        vector<int> dp(sequence.size());
        for(int i = word.size() - 1; i < sequence.size(); i++)
        {
            if(sequence.substr(i - n + 1, n) == word)
            {
                dp[i] = 1;
                if(i - n >= 0)
                {
                    dp[i] += dp[i - n];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};