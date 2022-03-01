# Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
# Q3. Sort squares of numbers in an array in ascending order
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        squared = []
        # Obtain square of number
        for num in nums:
            squared.append((num*num))
        # Sort array using inbuilt function
        squared.sort()
        return squared