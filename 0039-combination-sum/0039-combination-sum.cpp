class Solution {
public:
    
    void helper(int idx, int sum , int target , vector<int> &v, vector<int> &candidates , vector<vector<int>> & vec)
    {

       if(idx >= candidates.size ()){
        return ;
       }
        if(sum == target){
            vec.push_back(v);
            return ;
        }

       if(sum > target){
        return ;
        }

       

        //taking the value 
       
           v.push_back(candidates[idx]);
           helper(idx, sum+candidates[idx] ,target, v,candidates ,vec);
           v.pop_back();

        //not taking the value
            helper(idx+1, sum ,target , v,candidates ,vec);


    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>vec;
       vector<int>v;
        helper(0, 0 ,target, v, candidates ,vec );
        return vec;
    }
};