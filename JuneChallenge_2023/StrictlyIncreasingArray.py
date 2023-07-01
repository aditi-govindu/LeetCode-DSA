'''
Q1187. Description: Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.
'''

class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        n1 , n2, dp = len(arr1) , len(arr2) , {}
        arr2.sort()
        
        def solve(i , j , prev):
            if i == n1:
                return 0
            if (i,j,prev) in dp: 
                return dp[(i,j,prev)]

            k = bisect.bisect_right(arr2[j:],prev) + j
            ans = float('inf') if k == n2 else solve(i+1,k+1,arr2[k]) + 1

            if arr1[i] > prev:
                ans = min(ans,solve(i+1 , j ,arr1[i]))
            dp[(i,j,prev)] = ans

            return ans
        
        ans = solve(0,0,-float('inf'))
        return ans if ans != float('inf') else -1