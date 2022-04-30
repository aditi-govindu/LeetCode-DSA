'''
Q923. Description: Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.
'''

class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        MOD = 10**9 + 7
        res = 0
        arr.sort()
        
        for index, val in enumerate(arr):
            rem = target - val
            j, k = index+1, len(arr) - 1
            # Using 2 sum approach to advance left or right window when remaining is met
            while j < k:
                if arr[j] + arr[k] < rem:
                    j += 1
                elif arr[j] + arr[k] > rem:
                    k -= 1
                elif arr[j] != arr[k]:
                    left = right = 1
                    # If duplicate found, advance left pointer to skip it
                    while j + 1 < k and arr[j] == arr[j+1]:
                        left += 1
                        j += 1
                    # If duplicate found, advance right pointer to skip it
                    while k - 1 > j and arr[k] == arr[k-1]:
                        right += 1
                        k -= 1
                    # Multiply the duplicates seen to get multiplicity
                    res += left * right
                    res %= MOD
                    j += 1
                    k -= 1 
                else:
                    # Count M*(M-1) / 2 pairs only
                    res += (k-j+1) * (k-j) // 2
                    res %= MOD
                    break
        return res