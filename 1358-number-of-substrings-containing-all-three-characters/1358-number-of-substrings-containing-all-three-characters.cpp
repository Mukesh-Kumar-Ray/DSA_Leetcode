class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int j=0;
        int cnt=0;
        int n=s.size();

        unordered_map<char,int>ump;

        while(j<n){
            ump[s[j]]++;

            if(ump.size()<3){
                j++;
            }
            else if(ump.size() == 3){
                cnt=cnt+1+(n-j-1);
                while(ump.size() == 3){
                    ump[s[i]]--;
                    if(ump[s[i]]==0){
                        ump.erase(s[i]);
                    }
                    if(ump.size()==3){
                        cnt=cnt+1+(n-j-1);
                    }
                    i++;
                }
             j++;
            }

        } 
        return cnt;       

    }
};