'''
Q1760. Description: You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.
'''

class Solution(object):
    def minimumSize(self, nums, maxOperations):
        """
        :type nums: List[int]
        :type maxOperations: int
        :rtype: int
        """
        r = max(nums)
        l = 1
        ans = r

        while l < r:
            penalty = (l+r)/2
            ops = 0

            for num in nums:
                if num > penalty:
                        if num % penalty == 0:
                            ops += num / penalty - 1
                        else:
                            ops += num / penalty
            if ops <= maxOperations:
                ans = penalty
                r = penalty
            else:
                l = penalty + 1
        return ans