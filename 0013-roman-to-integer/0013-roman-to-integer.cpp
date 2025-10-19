class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        int sum = 0;
         int n = s.size();
         
        for (int i = 0; i < n; i++) {
            // if current value is smaller than next value, subtract it
            if (i + 1 < n && ump[s[i]] < ump[s[i + 1]]) {
                sum -= ump[s[i]];
            } else {
                sum += ump[s[i]];
            }
        }

        return sum;
    }
};