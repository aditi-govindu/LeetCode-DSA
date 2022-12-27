'''
Q76. Description: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.
'''
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""
        
        # Filter and consider letters in t only
        unique = collections.Counter(t)
        required = len(unique)
        filtered_s = []
        
        for i, char in enumerate(s):
            if char in unique:
                filtered_s.append((i, char))
                
        left = 0
        right = 0
        window_reached = 0
        window_counts = {}
        result = float('inf'), None, None
        
        while right < len(filtered_s):
            letter = filtered_s[right][1]
            window_counts[letter] = window_counts.get(letter, 0) + 1
            
            if window_counts[letter] == unique[letter]:
                window_reached += 1
            
            while left <= right and window_reached == required:
                letter = filtered_s[left][1]
                
                end = filtered_s[right][0]
                start = filtered_s[left][0]
                
                if end - start + 1 < result[0]:
                    result = (end - start + 1, start, end)
                    
                window_counts[letter] -= 1
                
                if window_counts[letter] < unique[letter]:
                    window_reached -= 1
                left += 1
            right += 1
        return '' if result[0] == float('inf') else s[result[1] : result[2] + 1]