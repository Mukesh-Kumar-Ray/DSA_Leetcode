class Solution {
public:
    int maxScore(vector<int>& card, int k) {

        int sum=0;
        int mx=INT_MIN;
        int n=card.size();

        for(int i=0;i<k;i++){
            sum += card[i];
        }

         mx=max(mx,sum);

        for(int i = k-1 ; i>=0;i--){
           sum -=card[i];
           sum +=card[n-1];
           n--;
           mx=max(sum,mx);
        }

       return mx;
    }
};