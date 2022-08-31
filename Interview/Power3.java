/*
Q326. Description: Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.
*/

class Solution {
    public boolean isPowerOfThree(int n) {
        
        // Convert number to string in base 3
        String number = Integer.toString(n,3);
        // Any number to base 3 must have exactly one 1 followed by any no. of 0
        return number.matches("^10*$");
    }
}