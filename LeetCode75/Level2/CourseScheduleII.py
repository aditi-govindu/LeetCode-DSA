'''
Q210. Description: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
'''

from collections import Counter, deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Prepare the graph
        adj_list = defaultdict(list)
        indegree = {}
        
        for dest, src in prerequisites:
            adj_list[src].append(dest)
            
            indegree[dest] = indegree.get(dest, 0) + 1
        
        # Identify nodes with 0 indegree, implying no pre-reqisites
        starting_nodes = deque([k for k in range(numCourses) if k not in indegree])
        topological_sorted_order = []
        
        while starting_nodes:
            start = starting_nodes.popleft()
            topological_sorted_order.append(start)
            
            if start in adj_list:
                # If prequisite course in solution, add current course and reduce degree
                for neighbour in adj_list[start]:
                    indegree[neighbour] -= 1
                    
                    if indegree[neighbour] == 0:
                        starting_nodes.append(neighbour)
                        
        return topological_sorted_order if len(topological_sorted_order) == numCourses else []