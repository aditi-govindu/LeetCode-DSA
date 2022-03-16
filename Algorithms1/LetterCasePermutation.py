'''
Q784. Description: Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.
'''

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        result = []
        # Add string to result as it is
        result.append(s)
        for i in range(len(s)):
            if s[i].isdigit():
                continue
            n = len(result)
            # Permutation of every string in result
            for j in range(n):
                permutation = list(result[j])
                # Swap case for letter and create new string
                permutation[i] = permutation[i].swapcase()
                result.append(''.join(permutation))
        return result