# Q549. Description: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
# You must implement a solution with a linear runtime complexity and use only constant extra space.

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hashmap = {}
        for val in nums:
            # If value not seen, set count to 1 and add to dictionary
            if val not in hashmap.keys():
                hashmap[val] = 1
            else:
                # Increment count of item already seen by 1
                hashmap[val]+=1
                
        # Return key value of item whose count is 1
        for key, val in hashmap.items():
            if val == 1:
                return key