class Solution {
public:
       void solve(int i,int sum,vector<int>& candidates,int target,vector<vector<int>>& vec,vector<int>& v){
        //base
         if(sum == target){  // tle  so i dont have to use set ..........
            vec.push_back(v);
            return ;
         }
          if (i >= candidates.size() || sum > target) {
            return;
        }


            v.push_back(candidates[i]);
            solve(i + 1, sum + candidates[i], candidates, target, vec, v);
            v.pop_back();

            int index = i+1;
         while( index < candidates.size() && candidates[index] == candidates[i]){
                  index++;
         }

          solve(index, sum , candidates, target, vec, v);

       }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>vec;
        // set<vector<int>>uniqueSet ; 
        sort(candidates.begin(), candidates.end());
        vector<int>v;
        solve(0,0,candidates,target,vec ,v);

        // for(auto i = uniqueSet.begin(); i != uniqueSet.end();i++){
        //     vec.push_back(*i);
        // }
         
        return vec;
    }
};