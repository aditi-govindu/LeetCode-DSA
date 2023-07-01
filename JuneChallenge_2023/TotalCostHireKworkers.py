'''
Q2462. Description: You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.
'''

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        # Store first k nodes
        head_workers = costs[:candidates]
        # Store last k workers, excluding ones in head_workers
        tail_workers = costs[max(candidates, len(costs) - candidates):]
        heapify(head_workers)
        heapify(tail_workers)

        answer = 0
        # Initialize next workers to add to priority queues
        next_head, next_tail = candidates, len(costs) - 1 - candidates

        for i in range(k):
            # Add lowest cost worker to answer, provided heaps are not empty
            if not tail_workers or head_workers and head_workers[0] <= tail_workers[0]:
                # If worker hired from head, add and increment head heap
                answer += heappop(head_workers)
                if next_head <= next_tail:
                    heappush(head_workers, costs[next_head])
                    next_head += 1

            else:
                # If worker hired from tail, add and decrement tail heap
                answer += heappop(tail_workers)
                if next_head <= next_tail:
                    heappush(tail_workers, costs[next_tail])
                    next_tail -= 1
        
        return answer