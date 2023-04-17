'''
Q744. Description: You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
'''

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        # List is sorted, hence find first element greater than target
        for letter in letters:
            if letter > target:
                return letter
        # Worst case - No letter, return 1st letter
        return letters[0]