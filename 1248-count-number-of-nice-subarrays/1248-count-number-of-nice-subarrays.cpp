class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                cnt++;
            }
            if (cnt < k) {
                j++;
            } else if (cnt == k) {
                int temp = i;
                while (nums[temp] % 2 == 0) {
                    temp++;
                }
                ans += (temp - i +1); // +1 for the subarray starting from the first odd
                j++;
            } else if (cnt > k) {
                while (cnt > k) {
                    if (nums[i] % 2 != 0) {
                        cnt--;
                    }
                    i++;
                }
                // Again count even numbers before first odd
                int temp = i;
                while (nums[temp] % 2 == 0) {
                    temp++;
                }
                ans += (temp - i + 1);
                j++;
            }
        }
        return ans;
    }
};