'''
Q383. Description: Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
'''

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag = collections.Counter(magazine)
        
        for letter in ransomNote:
            if letter in mag.keys() and mag[letter] > 0:
                mag[letter] -= 1
            else:
                return False
        return True
        
        