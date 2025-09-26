class Solution {
public:
    int solve(int i,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(amount == 0){
            return 0;
        }
        //never reach as if (amount - coins[i] >= 0) we have put this condition 
        // if(amount<0){
        //     return INT_MAX;
        // }
        if(i>=coins.size()){
            return INT_MAX;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        //pick
        int pick = INT_MAX;
        if (amount - coins[i] >= 0) {
            int res = solve(i, coins, amount - coins[i],dp);
            if (res != INT_MAX) {
                pick = 1 + res;
            }
        }
        //nont pic
        int notpick = solve(i+1,coins,amount,dp);

        return min(pick,notpick);

    }

    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        // int result =solve(0,coins,amount,dp);
        
        // return (result == INT_MAX) ? -1 : result;

        int n = coins.size();
        const int INF = 1e9; 
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 1; t <= amount; t++) {
                int pick = INF;
                if (t - coins[i] >= 0) {
                    pick = 1 + dp[i][t - coins[i]];
                }
                int notpick = dp[i + 1][t];
                dp[i][t] = min(pick, notpick);
            }
        }
        
        return dp[0][amount] >= INF ? -1 : dp[0][amount];
    }
};