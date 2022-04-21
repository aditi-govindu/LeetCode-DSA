/*
Q201. Description: Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int leftlen = 0;
        int rightlen = 0;
        int leftc = left;
        int rightc =  right;
        // If left length < right length, return 0
        while(leftc != 0)
        {
            leftlen++;
            leftc >>= 1;
        }
        while(rightc != 0)
        {
            rightlen++;
            rightc >>= 1;
        }
        if(leftlen < rightlen)
            return 0;
        else
        {
            // Perform bitwise AND of every number in given range
           int result = left;
           while(result != 0  && left < right)
           {
               left++;
               result &= left;
           }
           return result;
        } 
    }
};