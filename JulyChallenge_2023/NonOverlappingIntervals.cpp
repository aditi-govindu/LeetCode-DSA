/*
Q435. Description: Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

bool compareSecondElement(vector<int>& a, vector<int>& b)
{
    // Sort by end times or y in [x, y]
    return a[1] < b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int ans = 0;
        int k = INT_MIN;

        for(int i = 0; i < intervals.size(); i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];

            // Consider interval. No overlap caused
            if(x >= k)
                k = y;
            // Delete current interval and do not update k, as it overlaps
            else
                ans++;
        }
        return ans;
    }
};