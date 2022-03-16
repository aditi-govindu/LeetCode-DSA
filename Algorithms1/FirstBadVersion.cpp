// Q278. First bad version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Initialize
        int start = 0;
        int end = n;
        int mid = 0;
        int data;
        
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            // Check if version is bad, if yes, search in list of versions
            bool v = isBadVersion(mid);
            if(v)
            {
                data = mid;
                // Search in left side from 0 to mid-1
                end = mid - 1;
                
            }
            else
            {
                // Search in right side from mid+1 to end of array
                start = mid + 1;
            }
        }
        return data;
    }
};