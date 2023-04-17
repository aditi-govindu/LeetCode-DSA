/*
Q1574. Description: Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        // Scan from left to right to find start of decreasing array
        while(left + 1 < n && arr[left] <= arr[left + 1])
            left++;

        if(left == n -1)
            return 0;
        
        // Scan from right to left to find end of decreasing array
        while(right > left && arr[right - 1] <= arr[right])
            --right;
        
        int ans = min(n - left - 1, right);
        int j = right;
        int i = 0;

        // Delete nodes in left side or right side and find minimum possible deletions
        while(i <= left && j < n)
        {
            // Tighten the window and delete
            if(arr[j] >= arr[i])
            {
                ans = min(ans, j - i - 1);
                ++i;
            }
            // Losen the window since no delete allowed
            else
                j++;
        }
        return ans;
    }
};