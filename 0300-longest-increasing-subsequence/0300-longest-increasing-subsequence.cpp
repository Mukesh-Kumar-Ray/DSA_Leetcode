class Solution {
public:
    int solution (int i,int prevIdx,vector<int> &nums ,  vector<vector<int>> &dp){
        if(i>= nums.size()){
            return 0;
        }
        if (dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];
        int pick=0;
        if(prevIdx == -1 || nums[prevIdx]<nums[i]){
         pick = 1+solution(i+1,i,nums,dp);
        }
        int notpick = solution(i+1,prevIdx,nums,dp);

        return dp[i][prevIdx + 1] = max(pick,notpick);
        
    } 
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));

        return solution (0,-1,nums,dp);
        
    }
};