'''
Q703. Description: Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
'''
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        # Create min-heap from list
        self.k = k
        self.heap = nums
        heapq.heapify(self.heap)
        
        # Pop from list while length is less than k
        while(len(self.heap) > k):
            heapq.heappop(self.heap)

    def add(self, val: int) -> int:
        # Push value into heap
        heapq.heappush(self.heap, val)
        # After adding is length greater than k? If yes, pop new val
        if(len(self.heap) > self.k):
            heapq.heappop(self.heap)
        return self.heap[0]
        
# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)