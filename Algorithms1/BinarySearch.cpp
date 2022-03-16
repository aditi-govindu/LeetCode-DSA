// Q704. Binary search in ascending order array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialize
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
            {
                // Search in right side from mid+1 to end of array
                start = mid + 1;
            }
            else
            {
                // Search in left side from 0 to mid-1
                end = mid - 1;
            }
        }
        // Element not found
        return -1;
    }
};