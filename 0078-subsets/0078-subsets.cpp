class Solution {
public:
void recursiveFunction(vector<vector<int>> &vec , vector<int>&v , int i , vector<int> &nums){
    //base case;
    if(i==nums.size()){
        vec.push_back(v);
        return ;
    }

    //choose 
    v.push_back(nums[i]);
    recursiveFunction(vec , v, i+1 , nums);
    v.pop_back();

    //nont choose
    recursiveFunction(vec , v, i+1 , nums);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int>v;
        recursiveFunction(vec,v,0,nums);
        return vec;

        
    }
};