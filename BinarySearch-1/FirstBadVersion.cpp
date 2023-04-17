// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
Q278. Description: You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

*/

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int start = 0;
        int end = n;
        int mid = 0;
        int result = 0;
        
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            bool v = isBadVersion(mid);
            if(v)
            {
                // If mid is the bad version, return mid
                result = mid;
                end = mid - 1;
            }
            else
            {
                // Search in upper half for next bad version
                start = mid + 1;
            }
                
        }
        return result;
    }
};