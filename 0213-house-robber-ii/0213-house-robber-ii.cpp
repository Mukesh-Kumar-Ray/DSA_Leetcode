class Solution {
public:
    int solve (int i,int j,vector<int> &nums,vector<int> &memo){
        if(i >= j){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        
       int sum1= nums[i]+solve(i+2,j,nums,memo);
       int sum2 = solve(i+1,j,nums,memo );

       return memo[i]=max(sum1,sum2);
      
    }
    int rob(vector<int>& nums) {
        int j=nums.size();
        vector <int>memo1(j+1,-1);
        vector <int>memo2(j+1,-1);
        if (j == 0) return 0;
        if (j == 1) return nums[0];
        if (j == 2) return max(nums[0], nums[1]);

        int firstmax = solve(0,j-1,nums,memo1);
        int secondmax = solve(1,j,nums,memo2);

        return max(firstmax,secondmax);

        
    }
};