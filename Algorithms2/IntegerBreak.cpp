/*
Q343. Description: Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.
*/

/*
Concept: If an integer need to break in two parts, then to maximize their product those part should be equal. Thus, for n parts derivative of x^(n/x) should be minimum at e (3). Hence, divide numbers into sets of 3 or 2 to get maximum product.
*/

class Solution {
public:
    int integerBreak(int n) {
        // 2 is split as 1+1 so return 1*1
        if(n <= 2)
            return 1;
        // 3 is split as 2+1, so return 2*1
        if(n == 3)
            return 2;
        // 4 is split as 3+1 or 2+2, so return 2*2
        if(n == 4)
            return 4;
        if(n % 3 == 0)
            return (int)pow(3, n / 3);
        else if(n % 3 == 1)
            return 4 * (int)pow(3, n / 3 - 1);
        else
            return 2 * (int)pow(3, n / 3);  
    }
};