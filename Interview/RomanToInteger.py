'''
Q13. Description: Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M. Given a roman numeral, convert it to an integer.
'''

class Solution:
    def romanToInt(self, s: str) -> int:
        mapping = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        number = 0
        i = 0
        # Iterate over elements from left to right
        while(i < len(s)):
            if i+1 < len(s):
                # Compare current with element on right. If right is smaller, add current value
                if mapping[s[i]] >= mapping[s[i+1]]:
                    number += mapping[s[i]]
                    i = i+1
                else:
                    # If current is smaller than right, subtract current
                    # Eg: IV, 1 < 5 so number = -1
                    number -= mapping[s[i]]
                    i = i+1
            # Add first element value to number
            else:
                number += mapping[s[i]]
                i = i+1
        return number             