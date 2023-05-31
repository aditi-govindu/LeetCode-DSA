/*
Q1799. Description: You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.
*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int maxStates = 1 << nums.size(); // 2^(nums array size)
        int finalMask = maxStates - 1;

        // 'dp[i]' stores max score we can get after picking remaining numbers represented by 'i'.
        vector<int> dp(maxStates);

        // Iterate on all possible states one-by-one.
        for (int state = finalMask; state >= 0; state -= 1) {
            // If we have picked all numbers, we know we can't get more score as no number is remaining.
            if (state == finalMask) {
                dp[state] = 0;
                continue;
            }

            int numbersTaken = __builtin_popcount(state);
            int pairsFormed = numbersTaken / 2;
            // States representing even numbers are taken are only valid.
            if (numbersTaken % 2) {
                continue;
            }

            // We have picked 'pairsFormed' pairs, we try all combinations of one more pair now.
            // We itearte on two numbers using two nested for loops.
            for (int firstIndex = 0; firstIndex < nums.size(); firstIndex += 1) {
                for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); secondIndex += 1) {
                    // We only choose those numbers which were not already picked.
                    if (((state >> firstIndex) & 1) == 1 || ((state >> secondIndex) & 1) == 1) {
                        continue;
                    }
                    int currentScore = (pairsFormed + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                    int stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex);
                    int remainingScore = dp[stateAfterPickingCurrPair];
                    dp[state] = max(dp[state], currentScore + remainingScore);
                }
            }
        }

        // Returning score we get from 'n' remaining numbers of array.
        return dp[0];
    }
};