'''
Q802. Description: There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
'''

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        safe = [False] * n
        ans = []

        outgoing = [set(neighbors) for neighbors in graph]
        incoming = [set() for _ in range(n)]
        q = collections.deque()

        for i, js in enumerate(outgoing):
            if not js:
                q.append(i)
            for j in js:
                incoming[j].add(i)
        
        while q:
            j = q.popleft()
            safe[j] = True

            for i in incoming[j]:
                outgoing[i].remove(j)
                if len(outgoing[i]) == 0:
                    q.append(i)
        
        for i, is_safe in enumerate(safe):
            if is_safe:
                ans.append(i)

        return ans

