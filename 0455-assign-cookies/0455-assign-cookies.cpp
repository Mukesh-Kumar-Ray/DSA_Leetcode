class Solution {
public:
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
    }
};