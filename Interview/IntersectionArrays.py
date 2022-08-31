# Q674. Description: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = [] 
        hashmap = {}
        for val in nums1:
            # If number not seen before, set count to 1 and add to dictionary
            if val not in hashmap:
                hashmap[val] = 1
            else:
                # Increment count of number already seen by 1
                hashmap[val]+=1
                
        for val in nums2:
            # If number also in nums2, add it to result and decrement hashmap count
            if val in hashmap and hashmap[val] >= 1:
                result.append(val)
                hashmap[val]-=1
        return result