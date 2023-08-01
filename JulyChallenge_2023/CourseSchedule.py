'''
Q207. Description: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
'''

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        
        # Store adjacency list of edges entering a node
        adj = [[] for _ in range(numCourses)]
        for prereq in prerequisites:
            adj[prereq[1]].append(prereq[0])
            indegree[prereq[0]] += 1
        
        queue = deque()
        for i in range(numCourses):
            # Push all leaf nodes into queue
            if indegree[i] == 0:
                queue.append(i)
        
        nodesVisited = 0
        while queue:
            # BFS from leaf to parent nodes
            node = queue.popleft()
            nodesVisited += 1

            for neighbour in adj[node]:
                # Delete node -> neighbour edge (visited)
                indegree[neighbour] -= 1
                if indegree[neighbour] == 0:
                    # If node becomes a leaf, push into queue
                    queue.append(neighbour)
        
        return nodesVisited == numCourses