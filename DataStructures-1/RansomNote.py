'''
Q383. Description: Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
'''

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # Create dictionary of {letter : count} in magazine
        mag = collections.Counter(magazine)
        
        for letter in ransomNote:
            # If letter in note found in magazine, decrement count (Used once)
            if letter in mag.keys() and mag[letter] > 0:
                mag[letter] -= 1
            else:
                # Letter in note but not in magazine is invalid
                return False
        return True
        
        