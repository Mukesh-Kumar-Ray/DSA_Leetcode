class Solution {
public:

    int rec(string &s, string &rev, int i, int j , vector<vector<int>> &dp) {
        if(i >= s.size() || j >= rev.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == rev[j])
            return dp[i][j] = 1 + rec(s, rev, i + 1, j + 1,dp);
        
        return dp[i][j] = max(
            rec(s, rev, i + 1, j,dp),
            rec(s, rev, i, j + 1,dp)
        );
    }
    int minDistance(string word1, string word2) {
         vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
         int sameword =  rec(word1, word2, 0, 0,dp);
         return (word1.size()+word2.size())-(2*sameword);
    }
};