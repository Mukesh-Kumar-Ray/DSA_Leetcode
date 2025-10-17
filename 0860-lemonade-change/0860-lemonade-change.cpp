class Solution {
public:
// recursive solution 
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
        //return solveRE(bills, 0, 0, 0);

        //greedy approach 
        int fives = 0, tens = 0;
        for (int bill : bills) {
            if (bill == 5) {
                fives++;
            } else if (bill == 10) {
                if (fives == 0) {
                    return false;
                }
                fives--;
                tens++;
            } else {
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};