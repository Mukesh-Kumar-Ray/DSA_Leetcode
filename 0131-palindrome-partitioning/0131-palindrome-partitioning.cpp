class Solution {
public: 
    bool ispalendrom(string check, int start , int end){
        while(start <= end){
            if(check[start] != check[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;

    }
    void solution(int i,string &s, vector<vector<string>> &vec , vector<string> &v){
        if(i == s.size()){
            vec.push_back(v);
            return ; 
        }
      for(int index =i ;index<s.size();index++){
        string ans = s.substr(i,index-i+1);
        if (ispalendrom(s,i,index) == true){
            v.push_back(ans);
            solution(index+1,s,vec,v);
            v.pop_back();
        }
      }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<string>v;
        solution(0,s,vec ,v);
        return vec;
    }
};