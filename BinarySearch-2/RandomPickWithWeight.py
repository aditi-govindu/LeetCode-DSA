'''
Q528. Description: You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
'''

class Solution:
    # Your Solution object will be instantiated and called as such:
    # obj = Solution(w)
    # param_1 = obj.pickIndex()

    def __init__(self, w: List[int]):
        self.array = []
        self.SUM = sum(w)
        self.LENGTH = len(w)
        self.PERCENT = 100
        
        for idx, weight in enumerate(w):
            frequency = math.ceil(weight * self.LENGTH * self.PERCENT / self.SUM)
            self.array += [idx] * frequency
        

    def pickIndex(self) -> int:
        return self.array[random.randrange(len(self.array))]