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

        for (int j = i; j < candidates.size(); j++) {
            // skip duplicates at the same recursion level
            if (j > i && candidates[j] == candidates[j - 1]) continue;

            // prune (since sorted, no need to continue further)
            if (sum + candidates[j] > target) break;

            v.push_back(candidates[j]);
            solve(j + 1, sum + candidates[j], candidates, target, vec, v);
            v.pop_back();
        }

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