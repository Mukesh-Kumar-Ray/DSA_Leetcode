class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()>goal.size() || s.size() < goal.size()) return false;
        s=s+s;
        for(int i=0;i<s.size()-goal.size();i++){
            string sub = s.substr(i,goal.size());
            if(sub == goal) return true;
        }
        return false;
        
    }
};