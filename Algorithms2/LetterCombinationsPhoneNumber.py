'''
Q17. Description: Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
'''

import collections

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        # Mapping of letters to numbers
        mapping = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        
        stack = collections.deque([('',0)])
        path, solutions = [], []
        index = 0
        record, output = "", []
        
        while stack:
            # Pop characters from stack
            record, l = stack.pop()
            if l == len(digits):
                output.append(record)
                continue
            digit = digits[l]
            for letter in mapping[digit]:
                stack.append((record+letter, l+1))
        return output
            