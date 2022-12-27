'''
Q2131. Description: You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.
'''

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = collections.Counter(words)
        ans = 0
        centre = False
        
        for word, cnt in count.items():
            # Check if it is a palindrome
            if word[0] == word[1]:
                # Palindrome of even length implies add to ans 
                if cnt % 2 == 0:
                    ans += cnt
                else:
                    # Odd length can be used as centre
                    ans += cnt - 1
                    centre = True
            else:
                # Non palindrome strings pair must be considered only once
                if word[0] < word[1]:
                    ans += 2 * min(cnt, count[word[1] + word[0]])
        if centre == True:
            ans += 1
        return 2 * ans