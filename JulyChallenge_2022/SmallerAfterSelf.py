# Q315. Description: You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # Sort the array in time O(nlogn)
        sorted_values, ans = [], []
        for x in nums[::-1]:
            # Get index where element should go
            idx = bisect.bisect_left(sorted_values, x)
            sorted_values.insert(idx, x)
            ans.append(idx)
        # Return reverse of index positions
        return ans[::-1]