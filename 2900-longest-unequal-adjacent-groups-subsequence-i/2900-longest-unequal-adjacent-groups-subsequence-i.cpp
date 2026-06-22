class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int bestIdx = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(groups[i] != groups[j])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if(dp[i] > dp[bestIdx])
            {
                bestIdx = i;
            }
        }

        vector<string> answer;

        while(bestIdx != -1)
        {
            answer.push_back(words[bestIdx]);
            bestIdx = prev[bestIdx];
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};