class Solution {
public:
    vector<string> arr = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(int i , string &digits , string &str,vector<string> &vec){
        if(i>=digits.size()){
            vec.push_back(str);
            return ; 
        }
        string ans = arr[digits[i]-'0'-2];

        for(int j=0;j<ans.size();j++){
            str+=ans[j];
            solve(i+1,digits,str,vec);
            str.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
         vector<string> vec;
        if(digits.size() == 0){

            return vec;
        }
       
        string str;
        solve(0,digits,str ,vec);
        return vec;
    }
};