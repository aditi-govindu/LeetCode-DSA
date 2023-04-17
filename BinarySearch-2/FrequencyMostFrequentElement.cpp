/*
Q1838. Description: The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.
*/

class Solution 
{
private:
    bool isPos(vector<int>& a, int l, int k)
    {
        long long sum = 0;
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
            if(i >= l-1)
            {
                if(k >= (long long)a[i]*l - sum) 
                    return true;
                sum-=a[i-l+1];
            }
        }
        return false;
    }

public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int l = 1, h = nums.size(), mid;
        int ans = 1;
        while(l <= h)
        {
            mid = l + (h-l)/2;
            if(isPos(nums, mid, k))
            {
                ans = max(ans, mid);
                l = mid + 1;
            } 
            else
                h = mid - 1;
        }
        return ans;
    }
};