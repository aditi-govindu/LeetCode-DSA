'''
Q869. Description: You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.
'''
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        return any(cand[0] != '0' and bin(int("".join(cand))).count('1') == 1 for cand in itertools.permutations(str(n)))      