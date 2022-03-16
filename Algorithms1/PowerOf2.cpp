/*
Q231. Description: Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
        We can AND (&) n and n-1 and if the result is 0, it is power of 2. This works because if n is power of 2 with ith bit set, then in n-1, i will become unset and all bits to right of i will become set. Thus the result of AND will be 0.
        */
        return n>0 && !(n & n-1);
    }
};