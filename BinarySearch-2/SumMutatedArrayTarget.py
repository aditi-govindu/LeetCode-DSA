'''
Q1300. Description: Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarily a number from arr.
'''

class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort(reverse = True)
        maxi = arr[0]

        while arr and target >= arr[-1] * len(arr):
            target -= arr.pop()

        return int(round((target - 0.0001) / len(arr))) if arr else maxi