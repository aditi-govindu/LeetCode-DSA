/*
Q275. Description: Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in an ascending order, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

You must write an algorithm that runs in logarithmic time.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        // Apply binary search
        sort(citations.begin(), citations.end());

        int i = 0;
        int j = citations.size();
        int ans = 0;
        int n = citations.size();

        while(i <= j)
        {
            int mid = (i + j)/2;

            // Check citations not more than h
            int cnt = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();

            if(n - cnt >= mid)
            {
                ans = mid;
                i = mid + 1;
            } 
            else
                j = mid - 1;
        }
        return ans;
    }
};