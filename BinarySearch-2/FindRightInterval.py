'''
Q436. Description: You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
'''

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        if n <= 1:
            return [-1]
        
        # Sort intervals by start, end and position
        inter = sorted([[j,k,i] for i,[j,k] in enumerate(intervals)])

        beginnings = [i for i,_,_ in inter]

        ans = [-1] * n

        for i, j, k in inter:
            # Bisect left to search only in left half of array, from current place
            t = bisect.bisect_left(beginnings, j)
            if t < len(beginnings):
                ans[k] = inter[t][2]
        return ans