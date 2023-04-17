/*
Q34. Description: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int binarySearch(vector<int>&nums, int target, bool first)
    {
        int start = 0;
        int end = size(nums) - 1;
        int index = -1;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(target < nums[mid])
                end = mid - 1;
            else if(target > nums[mid])
                start = mid + 1;
            else
            {
                index = mid;
                // Reset index to find next index
                if(first)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector <int> results;
        int end = size(nums) - 1;
        results.push_back(binarySearch(nums, target, true));
        results.push_back(binarySearch(nums, target, false));
        return results;
    }
};