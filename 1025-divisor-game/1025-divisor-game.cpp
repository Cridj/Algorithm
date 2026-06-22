class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[1] = false;

        for(int i = 2; i <= n; i++)
        {
            for(int x = 1; x < i; x++)
            {
                if(i % x == 0)
                {
                    if(dp[i - x] == false)
                    {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};