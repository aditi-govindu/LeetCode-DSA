'''
Q56. Description: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
'''

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Sort based on lower limit
        intervals.sort(key = lambda x:x[0])
        MAX = float('inf')
        
        result = []
        for interval in intervals:
            # If interval not in result or not overlapping, append as is
            if not result or result[-1][1] < interval[0]:
                result.append(interval)
            else:
                result[-1][1] = max(result[-1][1], interval[1])
        return result
                
        