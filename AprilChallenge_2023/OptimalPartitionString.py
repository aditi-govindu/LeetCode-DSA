'''
Q2405. Description: Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.
'''

class Solution:
    def partitionString(self, s: str) -> int:
        # Make minimum partitions by maximizing unique letters in every partition
        i, count, flag = 0, 1, 0

        while i < len(s):
            val = ord(s[i]) - ord('a')
            # If bit is set, we have seen this letter
            if flag & (1 << val):
                # Reset partition and count substring
                flag = 0
                count += 1
            # Check bit is set or not
            flag |= 1 << val
            i += 1
        return count