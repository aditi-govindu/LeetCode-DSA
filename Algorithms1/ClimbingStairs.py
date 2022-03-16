'''
Q.70 You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Fibonacci series: Next element is sum of previous 2, ie: 1,1,2,3,5,8,13,21...
Problem is similar to fibonacci series for n+1 term

For n = 6, Fibonacci for 7 terms is: 1,1,2,3,5,8,13. Therfeore, combinations are 13
For n = 5, Fibonacci for 6 terms is: 1,1,2,3,5,8. Therefore, combinations are 8
For n = 4, Fibonacci for 5 terms is: 1,1,2,3,5. Therefore combinations are 5
'''

class Solution:
    def climbStairs(self, n: int) -> int:
        one_step = 1
        two_step = 1
        count = 0
        # For n = 1, only 1 option exists
        if n == 1:
            return 1
        for i in range(1,n):
            count = one_step + two_step
            one_step = two_step
            two_step = count
        return count
            