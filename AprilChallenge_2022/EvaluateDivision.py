'''
Q399. Description: You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
'''

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        graph = defaultdict(list)
        ans = []
        
        def bfs(target, queue, visited):
            while(queue):
                # Obtain pair of variables to match. Eg: a/b
                pair = queue.popleft()
                start = pair[0]
                ans = pair[1]
                # If a is a valid letter, check if it is visited
                if start in graph:
                    for node in graph[start]:
                        if node[0] not in visited:
                            # Not visited, append equation a, b*value to list
                            queue.append((node[0], ans * node[1]))
                        # If node[0] is the expected value, return its equation
                        if node[0] == target:
                            return ans*node[1]
                        visited.add(node[0])
            return -1.0
        
        # Create a dictionary mapping of nodes and values
        for nodes, value in zip(equations, values):
            graph[nodes[0]].append((nodes[1], value))
            graph[nodes[1]].append((nodes[0], 1 / float(value)))
        
        for pair in queries:
            # Add first pair of elements to visit
            q = deque([(pair[0], 1)])
            visited = set()
            visited.add(pair[0])
            answer = bfs(pair[1], q, visited)
            ans.append(answer)
        return ans     