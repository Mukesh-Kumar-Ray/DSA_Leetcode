class Solution {
public:
    int solution(int i , int sum ,vector<int>& nums) {
        if(i>=nums.size()){
            if(sum==0){
                return 1;
            }
            else{
               return 0;
            }
           
        }
        //add
        int add = solution(i+1,sum-nums[i] ,nums);

        //subtract
        int subtract = solution(i+1,sum+nums[i] ,nums);

        return add+subtract;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solution(0,target ,nums);
        
    }
};