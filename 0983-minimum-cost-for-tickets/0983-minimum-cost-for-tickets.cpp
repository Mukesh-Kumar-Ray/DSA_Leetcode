class Solution {
public:
    int solve(int ind, vector<int>& days, vector<int>& costs,vector<int> &dp) {
        if (ind >= days.size()) {
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }
        int j=ind;
        for(j=ind;j<days.size();j++){
            if(days[ind]+1<=days[j]){
                break;
            }
        }

        int opt1 = costs[0] + solve(j, days, costs ,dp);

         for(j=ind;j<days.size();j++){
            if(days[ind]+7<=days[j]){
                break;
            }
        }

        int opt2 = costs[1] + solve(j, days, costs,dp);

         for(j=ind;j<days.size();j++){
            if(days[ind]+30<=days[j]){
                break;
            }
        }
        int opt3 = costs[2] + solve(j, days, costs,dp);

        return dp[ind]=min(opt1, min(opt2, opt3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(0, days, costs,dp);
    }
};