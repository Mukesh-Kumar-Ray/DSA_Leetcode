class Solution {
public:
    bool solveRE(vector<int>& bills, int i, int five, int ten) {
        if (i == bills.size()) {
            return true;
        }
        int bill = bills[i];

        if (bill == 5) {
            return solveRE(bills, i + 1, five + 1, ten);
        } else if (bill == 10) {
            if (five > 0) {
                return solveRE(bills, i + 1, five - 1, ten + 1);
            }
        } else if (bill == 20) {
            if (ten > 0 && five > 0) {
                return solveRE(bills, i + 1, five - 1, ten - 1);
            } else if (five >= 3) {
                return solveRE(bills, i + 1, five - 3, ten);
            }
        }
        return false;
    }
    bool lemonadeChange(vector<int>& bills) {
        return solveRE(bills, 0, 0, 0);
    }
};