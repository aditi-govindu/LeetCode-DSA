'''
Q1218. Description: Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
'''

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        # Store maximum length of AP seen so far
        dp = {}
        answer = 1

        for num in arr:
            # Check existing subsequence that ends with element - difference
            before_ap = dp.get(num - difference, 0)
            # If num can be added to subsequence, increment length. Else, length = 1
            dp[num] = before_ap + 1
            answer = max(answer, dp[num])
        
        return answer