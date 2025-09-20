class Solution {
public:
void solve (int i ,vector<vector<int>> &vec ,vector<int> &v , vector<int>& nums){
    if(i >= nums.size()){
        vec.push_back(v);
        return ;
    }

    //pick 
    if(i < nums.size()){
    v.push_back(nums[i]);
    solve(i+1,vec,v,nums);
    v.pop_back();
    }

    //not pick
    int index = i+1;

    while(index <  nums.size() && nums[index] == nums[i]){
        index++;
    }

    solve(index,vec,v,nums);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>vec;
        vector<int>v;
        sort(nums.begin(),nums.end());
        solve(0,vec,v,nums);
        return vec;
        
    }
};