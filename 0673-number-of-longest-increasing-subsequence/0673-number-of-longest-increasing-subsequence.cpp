class Solution {
public:
     pair<int,int> calculateNoOfLIS(vector<int>& nums,int prev,int curr){
        if(curr==nums.size()){
            return {0,1};
        }

        pair<int,int> include;
        pair<int,int> exclude;

        if(prev==-1 || nums[curr]>nums[prev]){
            include=calculateNoOfLIS(nums,curr,curr+1);
            include.first++;
        }

        exclude=calculateNoOfLIS(nums,prev,curr+1);
        if(include.first==exclude.first){
            return {include.first,include.second+exclude.second};
        }
        else if(include.first>exclude.first){
            return include;
        }
        else{
            return exclude;
        }
    }

    pair<int,int> calculateNoOfLISMemoization(vector<int>& nums,int prev,int curr,vector<vector<pair<int,int>>> &dp){
        if(curr==nums.size()){
            return {0,1};
        }
        if(dp[prev+1][curr].first!=-1){
            return dp[prev+1][curr];
        }
        pair<int,int> include;
        pair<int,int> exclude;

        if(prev==-1 || nums[curr]>nums[prev]){
            include=calculateNoOfLISMemoization(nums,curr,curr+1,dp);
            include.first++;
        }

        exclude=calculateNoOfLISMemoization(nums,prev,curr+1,dp);
        if(include.first==exclude.first){
            dp[prev+1][curr]={include.first,include.second+exclude.second};
        }
        else if(include.first>exclude.first){
            dp[prev+1][curr]= include;
        }
        else{
            dp[prev+1][curr]= exclude;
        }
        return dp[prev+1][curr];
    }
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int,int>>> dp(nums.size()+1,vector<pair<int,int>>(nums.size()+1,{-1,-1}));
        //return calculateNoOfLIS(nums,-1,0).second;
        return calculateNoOfLISMemoization(nums,-1,0,dp).second;
    }
};