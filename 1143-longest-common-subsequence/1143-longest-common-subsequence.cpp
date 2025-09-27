class Solution {
public:

int solve(string &text1, string &text2,int n,int m,vector<vector<int>> &memo){
    if(n==0 || m==0){
        return 0;
    }
    if(memo[n][m] != -1) return memo[n][m];
    
    if(text1[n-1]==text2[m-1]){
         return memo[n][m]= 1+ solve(text1,text2,n-1,m-1,memo);
    }     
     else{
     return memo[n][m] =  max( solve(text1,text2,n,m-1,memo),solve(text1,text2,n-1,m,memo) );
     }
   
}
    int longestCommonSubsequence(string text1, string text2) {
         
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
       return  solve(text1,text2,n,m,memo);

        
    }
};