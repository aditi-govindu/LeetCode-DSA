'''
Q1802. Description: You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.
'''

class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        maxSum -= n
        l = 0
        r = maxSum

        # Binary search
        while l != r:
            mid = (l + r + 1) // 2
            s = max(0, mid - index - 1)
            e = max(0, mid - n + index)

            if mid*mid <= maxSum + (s * (s + 1) + e * (e + 1)) // 2:
                l = mid
            else:
                r = mid - 1
        return r + 1