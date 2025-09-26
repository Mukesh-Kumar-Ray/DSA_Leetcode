class Solution {
public:
    int maxContentChildren(vector<int>& g, vector<int>& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= g.size() || j >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[j] >= g[i]) {
            dp[i][j] = 1 + maxContentChildren(g, s, i + 1, j + 1, dp);
        } else {
           
            dp[i][j] = maxContentChildren(g, s, i, j + 1, dp);
        }

        return dp[i][j]; 
    }

     int memomaxContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int m = g.size();
        int n = s.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i=1; i<=m; i++) dp[i][0] = 0;
        for(int j=1; j<=n; j++) dp[0][j] = 0; 
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--) {
                // Option 1: Give this cookie to this child if possible
                if (s[j] >= g[i]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    // Option 2: Skip this cookie and try the next cookie for the same child
                    dp[i][j] = dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int j=0;
        int cnt=0;
        for(int i=0;i<g.size();i++){
            while(j<s.size()){
                if(g[i]<=s[j]){
                    j++;
                    cnt++;
                    break;
                }
                j++;
                
            }
        }
        return cnt;
        
        //memoization....

        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());
        // vector<vector<int>> dp(g.size(), vector<int>(s.size(), -1));
        // return maxContentChildren(g, s, 0, 0, dp);

        //dp----
        //return memomaxContentChildren(g, s);

        //space optimization,,,

        // int n=g.size(),m=s.size();
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // vector<int> prev(m+1,0), cur(m+1,0);

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(g[i-1]<=s[j-1]) cur[j]=1+prev[j-1];
        //         else cur[j]=prev[j];
        //     }
        //     prev=cur;
        // }
        // return prev[m];

    }
};