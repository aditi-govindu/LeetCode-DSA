'''
Q1493. Description: Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
'''

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # Count zeroes in current window
        zeroCount = 0
        longestWindow = 0
        start = 0

        for i in range(len(nums)):
            zeroCount += (nums[i] == 0)

            # Shrink window till zero count comes under the limit
            while zeroCount > 1:
                zeroCount -= (nums[start] == 0)
                start += 1

            # Update window as max of current window, largest seen so far
            longestWindow = max(longestWindow, i - start)

        return longestWindow