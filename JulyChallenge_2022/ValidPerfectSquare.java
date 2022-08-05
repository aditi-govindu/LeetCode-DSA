/*
Q367. Description: Given a positive integer num, write a function which returns True if num is a perfect square else False.
*/

class Solution {
    public boolean isPerfectSquare(int num) 
    {
        double val = Math.sqrt(num);
        // If no decimal part seen, it is perfect square
        double floored = Math.floor(val);
        if(val - floored == 0.0)
            return true;
        return false;
        
    }
}