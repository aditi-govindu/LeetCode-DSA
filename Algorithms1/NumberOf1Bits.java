/*
Q191. Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        // Convert binary number to string
        String test = Integer.toBinaryString(n);
        int count = 0;
        for(int i =0; i < test.length(); i++)
        {
            // Count no. of 1's seen
            if(test.charAt(i) == '1')
                count++;
        }
        return count;
    }
}