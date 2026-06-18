class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);

        for(int i = 0; i < numRows; i++)
        {
            v[i].resize(i + 1);
            for(int j = 0; j < i + 1; j++)
            {
                v[i][j] = 1;
            }
        }

        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < i + 1; j++)
            {
                if(j == 0 || j == i)
                    continue;
                v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
            }
        }
        return v;
    }
};