class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    void unionfun(int i,int j){
        int par_of_i = find(i);
        int par_of_j = find(j);
        
        if(par_of_i == par_of_j){
            return ;
        }

        if(rank[par_of_i] == rank[par_of_j] ){
            parent[par_of_i] = par_of_j ;
            rank[par_of_j]++ ;
        }

        else if(rank[par_of_i] > rank[par_of_j] ){
            parent[par_of_j] = par_of_i ;
        }

         else if(rank[par_of_i] < rank[par_of_j] ){
            parent[par_of_i] = par_of_j ;
        }

    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();

        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    unionfun(i+1,j+1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
        parent[i] = find(i);
        }
        unordered_set<int> s(parent.begin() +1, parent.end());
        return s.size();
        
    }
};