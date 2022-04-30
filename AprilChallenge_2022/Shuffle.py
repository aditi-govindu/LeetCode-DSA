class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.array = nums
        self.original = list(nums)

    def reset(self):
        """
        :rtype: List[int]
        """
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        """
        :rtype: List[int]
        """
        aux = list(self.array)
        for num in range(len(self.array)):
            remove = random.randrange(len(aux))
            self.array[num] = aux.pop(remove)
        return self.array

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()