'''
Q139. Description: Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        def Dynamic(target, memo = {}):
            # If word is found, return true
            if target in memo:
                return memo[target]
            elif target == '':
                return True
            for word in wordDict:
                # If word is found and start index is same as that of target, return true
                if word in target and target.index(word) == 0:
                    # Recursive call to check for every letter in word and target
                    if Dynamic(target[len(word):], memo):
                        memo[target] = True
                        return memo[target]
            memo[target] = False
            return memo[target]
        
        return Dynamic(s)             