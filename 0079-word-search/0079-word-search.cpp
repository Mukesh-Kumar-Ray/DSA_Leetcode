class Solution {
public: 
    bool solve( int i,int j,int k,vector<vector<char>>& board, string word ,vector<vector<int>>& check){

          if(board[i][j] != word[k]){
            return false;
          }

        if(k == word.size()-1){
            return true;
        }

        // if(i>= board.size() || j>= board[0].size() || i<0 || j<0 ){
        //     return false;
        // }
        bool top=false,down=false,right=false,left=false;

        if(j+1 < board[0].size()  && check[i][j+1] == 0){
            check[i][j+1]=1;
             right =solve(i , j+1 ,k+1 ,board,word,check);
             check[i][j+1]=0;
        }
        if(i+1 < board.size()  && check[i+1][j] == 0){
            check[i+1][j]=1;
            down =solve(i+1 , j ,k+1 ,board,word,check);
            check[i+1][j]=0;
        }
        if(j-1 >= 0 && check[i][j-1] == 0){
              check[i][j-1]=1;
            left = solve(i , j-1 ,k+1 ,board,word,check);
            check[i][j-1]=0;
        }
        if(i-1 >= 0 && check[i-1][j] == 0){
            check[i-1][j]=1;
            top = solve(i-1 , j ,k+1 ,board,word,check);
            check[i-1][j]=0;
        }

        return top || down || left || right ;

    }
    bool exist(vector<vector<char>>& board, string word) {
        // vector<vector<int>>check;
        // for(int i=0;i<board.size();i++){
        //     for(int j=0;j<board[0].size();j++){
        //         check[i][j]=0;
        //     }
        // }

        vector<vector<int>> check(board.size(), vector<int>(board[0].size(), 0));

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && check[i][j] == 0){
                    check[i][j]=1;
                    if(solve(i, j, 0, board, word, check)){
                        return true;
                    }
                    check[i][j]=0;
                }
            }
        }
        return false;
    }
};