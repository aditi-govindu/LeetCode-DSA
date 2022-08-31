'''
Q412. Description: Given an integer n, return a string array answer (1-indexed) where:
answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
'''

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        solution = []
        for i in range(1,n+1):
            div3 = (i%3 == 0)
            div5 = (i%5 == 0)
            if div3 and div5:
                solution.append("FizzBuzz")
            elif div3:
                solution.append("Fizz")
            elif div5:
                solution.append("Buzz")
            else:
                solution.append(str(i)) 
        return solution