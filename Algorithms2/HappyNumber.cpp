/*
Q202. Description: Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/

class Solution {
public:
    int SumSquare(int num)
    {
        // Calculate sum of square of digits
        int sum = 0;
        while(num > 0)
        {
            int digit = num % 10;
            sum += pow(digit, 2);
            num = num / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) 
    {
        unordered_map<int, int> seen(0);
        
        while(true)
        {
            // If n is 1, return true
            n = SumSquare(n);
            if(n == 1)
                return true;
            // Cycle detected, set hash value to 1
            if(seen[n] == 1)
                break;
            else
                seen[n] = 1;
        }
        if(n == 1)
            return true;
        return false;
    }
};