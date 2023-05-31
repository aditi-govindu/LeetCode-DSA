'''
Q2542. Description: You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.
'''

class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        # Store nums1, nums2 as pairs and sort by descending order of nums2
        pairs = [(a,b) for a,b in zip(nums1, nums2)]
        pairs.sort(key = lambda x : -x[1])

        # Track top k elements using heap
        top_k_heap = [x[0] for x in pairs[:k]]
        top_k_sum = sum(top_k_heap)
        heapq.heapify(top_k_heap)

        # Sum of first k pairs in the heap
        answer = top_k_sum * pairs[k - 1][1]

        # Iterate over every nums2[i] as minimum from nums2
        for i in range(k, len(nums1)):
            # Remove smallest integer and add nums[i] to top k elements
            top_k_sum -= heapq.heappop(top_k_heap)
            top_k_sum += pairs[i][0]
            heapq.heappush(top_k_heap, pairs[i][0])

            # Update answer
            answer = max(answer, top_k_sum * pairs[i][1])
        
        return answer