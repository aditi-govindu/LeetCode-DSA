/*
Q258. Description: Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:
    int Sum(int n)
    {
        // Separate digits in number and add them
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
        // While sum of digits is a 2 digit number, split and find sum
        while(res > 9)
            res = Sum(res);
        return res;
    }
};