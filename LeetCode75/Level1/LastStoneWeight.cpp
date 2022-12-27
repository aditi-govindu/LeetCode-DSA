/*
Q1046. Description: You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Store stones in descending order of weights
        sort(stones.begin(), stones.end(), greater<int>());
        for(int i = 0; i < stones.size() - 1; i++)
        {
            // If bigger stone found, smash it and set other stone as non usable - 1001
            if(stones[i] > stones[i+1] && stones[i] != 1001)
            {
                stones[i] = stones[i] - stones[i+1];
                stones[i+1] = 1001;
            }
            else if(stones[i] == stones[i+1])
            {
                // Both stones are not usable if equal - 1001
                stones[i] = 1001;
                stones[i+1] = 1001;
            }
            // Rebuild heap or sorting of stones in descending order
            sort(stones.begin(), stones.end(), greater<int>());
        }
        // If last left stone is unusable, return 0. Else return min
        int result = *min_element(stones.begin(), stones.end());
        return result == 1001 ? 0 : result;
    }
};