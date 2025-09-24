class Solution {
public:
    int min_sum_to_reach_botom_row(vector<vector<int>>& triangle, int row,
                                   int col, int target,
                                   vector<vector<int>>& dp) {
        if (row == target - 1) {
            return triangle[row][col];
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int down =
            min_sum_to_reach_botom_row(triangle, row + 1, col, target, dp);
        int diagonal =
            min_sum_to_reach_botom_row(triangle, row + 1, col + 1, target, dp);

        int mn = min(down, diagonal);

        return (dp[row][col] = mn + triangle[row][col]);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        //     int target = triangle.size();
        //    vector<vector<int>> dp(target+1,vector<int>(target+1,-1));
        //    return min_sum_to_reach_botom_row(triangle,0,0,target,dp);

        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (i == n - 1) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int down = dp[i+1][j]; // min_sum_to_reach_botom_row(triangle, row + 1, col,
                                                      //target, dp);
                int diagonal = dp[i+1][j+1];//min_sum_to_reach_botom_row(triangle, row + 1,
                                                         // col + 1, target, dp);

                int mn = min(down, diagonal);

                dp[i][j] = mn + triangle[i][j];
            }
        }
        return dp[0][0] ;//min_sum_to_reach_botom_row(triangle, 0, 0, n, dp);
    }
};