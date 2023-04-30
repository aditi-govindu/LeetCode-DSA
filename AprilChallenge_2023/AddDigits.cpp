/*
Q258. Description: Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:
    int Sum(int n)
    {
        int total = 0;
        while(n > 0)
        {
            int digit = n % 10;
            total += digit;
            n = n / 10;
        }
        return total;
    }
    
    int addDigits(int num) {
        int res = Sum(num);
        while(res > 9)
            res = Sum(res);
        return res;
    }
};