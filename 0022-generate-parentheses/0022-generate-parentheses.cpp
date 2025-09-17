class Solution {
public:

    void revursiveGenerateParaenthesis(int n ,string &str ,int open ,int close , vector<string> &result){
         ///base case
         if(open == 0 && close == 0){
            result.push_back(str);
            return ; 
         }
         //include the "(";
        
         if(open > 0 ){
         str+="(";
         revursiveGenerateParaenthesis( n  , str ,open -1 ,close ,  result);
         str.pop_back();
         }
         //exclude the "(";
         if(close >0 && open!=close){
             str+=")";
            revursiveGenerateParaenthesis(n ,str ,open,close -1 , result);
            str.pop_back();
         }
         


    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string str = "";
        int open =n;
        int close = n;

        revursiveGenerateParaenthesis(n , str, open ,close ,  result);
        return result;
        
    }
};