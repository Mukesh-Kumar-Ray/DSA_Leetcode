class Solution {
public:
    int min_falling_path_sum(vector<vector<int>>& matrix, int j, int i,
                             vector<vector<int>>& t) {
        if (j < 0 || j >= matrix[0].size()) {
            return INT_MAX;
        }
        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }

        if (t[i][j] != -1)
            return t[i][j];
        int down = min_falling_path_sum(matrix, j, i + 1, t);
        int rightd = min_falling_path_sum(matrix, j + 1, i + 1, t);
        int leftd = min_falling_path_sum(matrix, j - 1, i + 1, t);

        return t[i][j] = matrix[i][j] + min(down, min(rightd, leftd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int row=matrix.size();

        // int ans=INT_MAX;
        // vector<vector<int>> t(row+1, vector<int> (matrix[0].size()+1, -1));
        // for(int i=0;i<row;i++){
        //    ans=min(ans, min_falling_path_sum(matrix,i,0,t));

        // }
        // return ans;

        // tabulation in dp ................

        int n = matrix.size();

        // dp[i][j] = minimum path sum starting from (i, j) to bottom
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 1️⃣ Base case: last row = same as matrix last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // 2️⃣ Fill the table from bottom-1 row up to top row
        for (int i = n - 2; i >= 0; i--) { // row (start from n-2)
            for (int j = 0; j < n; j++) {  // col
                int down = dp[i + 1][j];   // directly below

                int left =
                    (j > 0) ? dp[i + 1][j - 1] : INT_MAX; // left diagonal
                int right =
                    (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX; // right diagonal

                dp[i][j] = matrix[i][j] + min(down, min(left, right));
            }
        }

        // 3️⃣ Answer = min of first row (since we can start at any column in row
        // 0)
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};