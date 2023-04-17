/*
Q875. Description: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

class Solution {
public:
    long long timeTaken(vector<int>& piles, int k)
    {
        long long ans = 0;
        // Bananas eaten in the hour are size/k + any leftover from previous
        for(int i = 0; i < piles.size(); i++)
            ans += (piles[i]/k) + (piles[i]%k != 0);
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            // Binary search to find least time
            if(timeTaken(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};