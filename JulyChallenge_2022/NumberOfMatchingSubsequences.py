'''
Q792. Description: Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
'''

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        ln = len(words)
        dct = defaultdict(list)
        wordlevels = [0]*ln
        
        for i, word in enumerate(words):
            dct[word[0]].append(i)
        
        ans = 0
        for char in s:
            if char not in dct:
                continue
            lst = dct.pop(char)
            for i in lst:
                wordlevels[i] += 1
                if wordlevels[i] < len(words[i]):
                    dct[words[i][wordlevels[i]]].append(i)
                else:
                    ans += 1
        return ans