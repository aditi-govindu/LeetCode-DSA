'''
Q1385. Description: Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
'''

class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        result = 0
        for elem1 in arr1:
            temp = 0
            for elem2 in arr2:
                if abs(elem1 - elem2) > d:
                    temp += 1
            if temp == len(arr2):
                result += 1
        return result
