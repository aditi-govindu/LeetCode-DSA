'''
Q1338. Description: You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.
'''
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        # Sort dictionary count of values in descending order
        sizes = collections.Counter(arr).most_common()
        n = len(arr)
        target = len(arr)//2
        counter = 0
        
        for key in sizes:
            # Decrement target by maximum count seen
            n -= key[1]
            counter += 1
            if n <= target:
                break
        return counter