class Solution {
public:
    int myAtoi(string s) {

        bool firstZero=true;
        bool signCheck =true;
        bool emptycheck =true;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                 if(emptycheck == false){
                    break ;
                }
                else{
                 continue;
                }
            }
            if(s[i]=='0' && firstZero == true){ 
                 signCheck =false;
                 emptycheck =false;
                 continue;
            }
             if(s[i]=='+' || s[i] == '-'){
                if(signCheck == false){
                    break ;
                }
                else{
                  temp +=s[i];
                  signCheck =false;
                  emptycheck =false;
                }
                
            }
            else{
                if((s[i]=='1') || (s[i] == '2') || (s[i]=='3') || (s[i] == '4') || (s[i]=='5') || (s[i] == '6') || (s[i]=='7') || (s[i] == '8') || (s[i]=='9') || (s[i]=='0' && firstZero == false) ){
                    temp +=s[i];
                    firstZero = false;
                    signCheck =false;
                    emptycheck =false;
                }
                else{
                    break;

                }
            }
         

        }

       if (temp == "" || temp == "-" || temp == "+") return 0;

        try {
            return stoi(temp);
        } catch (...) {
            // handle overflow manually
            if (temp[0] == '-') return INT_MIN;
            else return INT_MAX;
        }

    }
};