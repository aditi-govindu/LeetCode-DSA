'''
Q659. Description: You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
'''

class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        subsequence = collections.defaultdict(int)
        num_count = collections.Counter(nums)
        
        for num in nums:
            if not num_count[num]:
                continue
            
            if subsequence[num - 1] > 0:
                # Increment count of subsequences ending in num
                subsequence[num - 1] -= 1
                subsequence[num] += 1
            else:
                if not num_count[num + 2] or not num_count[num + 1]:
                    return False
                # Decrement remaining occurences of num from list
                num_count[num + 2] -= 1
                num_count[num + 1] -= 1
                subsequence[num + 2] += 1
            num_count[num] -= 1
        return True
                