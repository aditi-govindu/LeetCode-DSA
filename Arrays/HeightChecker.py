""""
 The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].
"""""

# Q13. Sort array in ascending order and check with original array if it is in order or not
class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        expected = list()
        # Copy array into expected list
        expected[:] = heights
        # Sort original array
        heights.sort()
        count = 0
        for i, val in enumerate(heights):
            # If element is not in correct sorted position, increment count
            if heights[i] != expected[i]:
                count+=1
        return count