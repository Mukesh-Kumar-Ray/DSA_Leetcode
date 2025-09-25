class Solution {
public:
    bool solution(int i, int target, vector<int>& nums) {
        if (target == 0) {
            return true;
        }

        if (i >= nums.size()) {
            return false;
        }

        if (target < 0) {
            return false;
        }

        // pick
        bool first = solution(i + 1, target - nums[i], nums);

        // not pick
        bool second = solution(i + 1, target, nums);

        return (first || second);
    }

    bool memo(int i,int target, vector<int>& nums, vector<vector<int>>& vec) {
        if (target == 0) {
            return true;
        }

        if (i >= nums.size()) {
            return false;
        }

        if (target < 0) {
            return false;
        }
        if (vec[i][target] != -1) {
            return vec[i][target];
        }

        // pick
        bool first = memo(i + 1, target - nums[i], nums, vec);

        // not pick
        bool second = memo(i + 1, target, nums, vec);

        return vec[i][target] = max(first, second);
    }

    bool tabulation(int i,int target, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
        // for(int i=0 ;i<=n;i++){
        //     dp[i][0]=true;
        // }
       
        for (int i = n; i>=0; i--) {
            for (int j = 0; j <= target; j++) {
                 if (j == 0) {
                    dp[i][j]=true;
                       continue;
                 }

        if (i >= nums.size()) {
             dp[i][j]=false;
                       continue;
        }

        if (j < 0) {
             dp[i][j]=false;
                       continue;
           
        }
                // pick
                bool first = (j>=nums[i]) ?  dp[i + 1][j - nums[i]] : false ; // tabulation(i + 1, target - nums[i], nums, vec);

                // not pick
                bool second = (i<=nums.size()) ?  dp[i + 1][j] : false ; // tabulation(i + 1, target, nums, vec);

                dp[i][j] = first || second;
            }
        }

        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int target = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }

        target = sum / 2;

        // return solution(0,target,nums);

        // vector<vector<int>> vec(n+1, vector<int>(target + 1, -1));

        // return memo(0, target, nums ,vec);

        
        return tabulation(0,target, nums);
    }
};