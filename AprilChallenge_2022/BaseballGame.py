'''
Q682. Description: You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.
'''

class Solution:
    def calPoints(self, ops: List[str]) -> int:
        result = []
        for char in ops:
            try:
                # Append number to result
                test = (int)(char)
                result.append(test)
            except:
                if char.isnumeric(): 
                    result.append((int)(char))
                # If C, pop last entered number
                if char == 'C':
                    result.pop()
                # If D, duplicate last entered number
                if char == 'D':
                    i = len(result) - 1
                    result.append(result[i] * 2)
                # If +, add last 2 numbers
                if char == '+':
                    k = len(result) - 1
                    l = len(result) - 2
                    result.append(result[k] + result[l])
        return sum(result)