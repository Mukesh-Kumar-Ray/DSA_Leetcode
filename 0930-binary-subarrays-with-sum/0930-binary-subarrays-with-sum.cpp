class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            sum += nums[head];
            while (sum > goal && tail <= head) {
                sum -= nums[tail];
                tail++;
            }
            result += head - tail + 1;
        }
        return result;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {

        // bu using hash map ........................
        /*
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

        */

        //modified sliding window....................
        return atMost(nums, k) - atMost(nums, k-1);
        
    }
};