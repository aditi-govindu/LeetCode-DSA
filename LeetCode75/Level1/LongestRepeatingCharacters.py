'''
Q424. Description: You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

'''
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if(len(s) == 1):
            return 1
        
        l, r, max_length, max_num_of_repeating_char = 0, 0, 0, 0
        char_count_list = [0] * 26
        
        for char in s:
            char_index = ord(char) - ord('A')
            char_count_list[char_index] += 1
            
            # Every time char count is incremented, check if lead is repeated
            max_num_of_repeating_char = max(max_num_of_repeating_char, char_count_list[char_index])
            
            # Find no. of characters to replace
            # If length of window r-l+1 <= k, replace the characters
            
            num_of_char_to_replace = (r - l + 1) - max_num_of_repeating_char
            if num_of_char_to_replace <= k:
                max_length = (r - l + 1)
            else:
                char_count_list[ord(s[l]) - ord('A')] -= 1
                l += 1
            
            r += 1
            
        return max_length