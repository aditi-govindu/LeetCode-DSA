'''
Q797. Description: Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
'''

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        result = []
        
        # Recursive function to explore all paths using inbuilt stack
        def FindPath(index, current):
            # If current node is destination, append solution path to result
            if index == len(graph) - 1:
                result.append(current)
            else:
                # Search for neighbouring nodes and add to path finding process
                for i in graph[index]:
                    FindPath(i, current + [i])
        
        # Driver code
        FindPath(0,[0])
        
        return result