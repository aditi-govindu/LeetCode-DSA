'''
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.
'''
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        
        word_len = len(words[0])
        substring = word_len * k
        # create hashmap of words and indexes
        word_count = collections.Counter(words)
        
        def check(i):
            rem = word_count.copy()
            words_used = 0
            
            for j in range(i, i+substring, word_len):
                sub = s[j : j + word_len]
                if rem[sub] > 0:
                    rem[sub] -= 1
                    # Increment count of matches seen so far
                    words_used += 1
                else:
                    break
            
            return words_used == k
        
        answer = []
        for i in range(n-substring + 1):
            if check(i):
                # If substring found and length is sufficient, append index to answer
                answer.append(i)
        return answer