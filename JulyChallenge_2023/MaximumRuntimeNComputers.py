'''
Q2141. Description: You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.
'''

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        left, right = 1, sum(batteries) // n

        while left < right:
            # Try to reach target time using all batteries
            target = right - (right - left) // 2
            extra = 0

            for power in batteries:
                extra += min(power, target)
            
            if extra // n >= target:
                # Only target power can be used
                left = target
            else:
                # All power can be used in the battery
                right = target - 1

        return left
