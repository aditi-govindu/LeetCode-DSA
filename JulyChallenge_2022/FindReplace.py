'''
Q890. Description: Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
'''

class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(word):
            forward = {}
            reverse = {}
            
            for w, p in zip(word, pattern):
                # if mapping of forward not same as reverse, permutation not found
                if w not in forward: forward[w] = p
                if p not in reverse: reverse[p] = w
                if(forward[w], reverse[p]) != (p, w):
                    return False
            return True
            
        return filter(match, words)