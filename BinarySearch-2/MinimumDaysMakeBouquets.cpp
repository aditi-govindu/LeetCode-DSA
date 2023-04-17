/*
Q1482. Description: You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

class Solution 
{
    public:
    bool check(vector<int>& bloomDay, int m, int k,int mid)
    {
        int c = 0;
        int total = 0;

        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid)
            {
                c++;
                if(c == k)
                {
                    total++;
                    c = 0;
                }
            }
            else 
                c = 0;
        }

        if(total >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int st=0;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(st <= end)
        {
            int mid=(st + end) / 2;
            if(check(bloomDay, m, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                st = mid+1;
        }
        return ans;
    }
};