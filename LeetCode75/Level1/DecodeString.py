'''
Q394. Description: Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
'''

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        
        for element in s:
            if element == '[':
                curr = ''
                # If opening bracket seen after number, store all letters in stack
                while len(stack) and stack[-1].isdigit():
                    last = stack.pop()
                    curr = last + curr
                stack.append(curr)
                stack.append(element)
                
            elif element == ']':
                rep = ''
                # Closing bracket seen, repeat all characters present in []
                while stack[-1] != '[':
                    rep = stack[-1] + rep
                    stack.pop()
                
                bracket = stack.pop()
                number = stack.pop()
                # Repeat characters by no. of times outside the bracket
                stack.append((int)(number) * rep)
            
            else:
                stack.append(element)
                
        return ''.join(stack)