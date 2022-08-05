'''
Q118. Description: Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
'''

class Solution:
    def coef(self, n, k):
        # Find binomial coefficient of current row and element
        res = 1
        if (k > n-k):
            k = n-k
        for i in range(0, k):
            res = res * (n-i)
            res = res // (i+1)
        return res
    
    def generate(self, numRows: int) -> List[List[int]]:
        sol = []
        for line in range(numRows):
            curr = []
            for i in range(0, line+1):
                curr.append(self.coef(line, i))
            sol.append(curr)
        return sol
        