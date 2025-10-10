class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j =0;
        int mx=INT_MIN;
        int maxFreq = 0;
        unordered_map<char,int>ump;

        while(j < s.size()){
            ump[s[j]]++;
            maxFreq = max(maxFreq, ump[s[j]]);

            if((j - i + 1) - maxFreq < k){
                mx=max(mx,j-i+1);
                j++;
            }
            else if((j - i + 1) - maxFreq == k){
                mx=max(mx,j-i+1);
                j++;
            }
            else{
                while((j - i + 1) - maxFreq > k){
                  ump[s[i]]--;
                  if(ump[s[i]] == 0){
                    ump.erase(s[i]);
                  }
                  i++;
                }
                j++;
            }
        }
        return mx;

    
    }
};