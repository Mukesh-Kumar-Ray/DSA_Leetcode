class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int mx = 0;
        int count_zero = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                count_zero++;
            }

            if (count_zero < k) {
                j++;
            } else if (count_zero == k) {
                mx = max(mx, j - i + 1);
                j++;
            } else if (count_zero > k) {
                while (count_zero > k) {
                    if (nums[i] == 0) {
                        count_zero--;
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};