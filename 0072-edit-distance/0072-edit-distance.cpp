class Solution {
public:
    int solution(string word1, string word2 , int i,int j,vector<vector<int>> &dp){
        //base case;
        if(j >= word2.size()){
            return word1.size()-i;
        }
        if(i >= word1.size()) {
            return word2.size() - j;
            } 
            if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(word1[i] == word2[j]){
           ans = solution(word1,word2,i+1,j+1,dp);
        }
        else{
           int insertop = 1+ solution(word1,word2,i,j+1,dp);
           int deleteop = 1+  solution(word1,word2,i+1,j,dp);
           int replaceop = 1+ solution(word1,word2,i+1,j+1,dp);

           ans = min(insertop,min(deleteop,replaceop));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
         vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));

        return solution(word1,word2,0,0,dp);
    }
};