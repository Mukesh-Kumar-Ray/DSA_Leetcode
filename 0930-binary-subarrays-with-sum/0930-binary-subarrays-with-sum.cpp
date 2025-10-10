class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        /*
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;

        while(j < nums.size()){
            sum += nums[j];
            if(sum < k){
                j++;
            }
            else if(sum == k){
                ans++;
                j++;
            }
            else if(sum > k ){
                while(sum > k && i <= j){ // this condition keep in mind (&& i <= j)
                    sum-=nums[i];
                    i++;
                    if (sum == k) ans++; // count subarray after shrink
                }
                j++;
            }
        }
        return ans;
        */

        // bu using hash map ........................
        unordered_map<int,int>ump;
        int sum =0;
        int cnt=0;
        ump[sum]=1;

        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(ump.find(sum-k) != ump.end()){
                cnt +=ump[sum-k];
                ump[sum]++;

            }
            else{
                ump[sum]++;
            }
        }
        return cnt;
        
    }
};