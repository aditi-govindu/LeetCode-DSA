// Q35. Search insert position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        // Binary search for element
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        // Element not found. Target > middle, return start middle + 1
        return (target >= nums[mid]) ? start : mid;
    }
};