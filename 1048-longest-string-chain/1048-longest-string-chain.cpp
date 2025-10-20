class Solution {
public:
    bool match(string& a, string& b) {
         if (b.size() - a.size() != 1)
            return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j])
                i++;
            j++;
        }
        return i == a.size();
    }
    int solve(int i,int prevIndex, vector<string>& words, vector<vector<int>>& dp) {
        // base case
        if (i >= words.size()) {
            return 0;
        }

       if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

        // include
        int include=0;
        if (prevIndex == -1 || match(words[prevIndex], words[i])) {
                include = 1 + solve(i + 1,i, words, dp);
        }

        // exclude
        int exclude = solve(i + 1,prevIndex, words, dp);

            // return
        return dp[i][prevIndex + 1] = max(include, exclude);
    }
    static bool compareStringsBySize(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compareStringsBySize);
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1,words,dp);
    }
};