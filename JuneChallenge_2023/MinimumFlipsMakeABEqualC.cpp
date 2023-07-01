/*
Q1318. Description: Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
*/

class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int answer = 0;
        while(a != 0 | b != 0 | c != 0)
        {
            if((c & 1) == 1)
            {
                // If bit at c is 1, but a and b bits are 0, flip is needed
                if((a & 1) == 0 && (b & 1) == 0)
                    answer++;
            }               
            else
            {
                // Answer is either a or b bit equal to 1 
                answer += (a & 1) + (b & 1);
            }
            // Shift all terms to left by 1 place
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return answer;
    }
};