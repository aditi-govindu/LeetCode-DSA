'''
Q1456. Description: Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
'''

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        count = 0
        vowels = {'a','e','i','o','u'}

        # Frequency count of vowels in first k letters
        for i in range(k):
            count += int(s[i] in vowels)
        answer = count

        # Count vowels in window sizes of k
        for i in range(k, len(s)):
            # New vowel count increased
            count += int(s[i] in vowels)
            # Vowel seen, count decrease
            count -= int(s[i - k] in vowels)
            answer = max(answer, count)
        
        return answer