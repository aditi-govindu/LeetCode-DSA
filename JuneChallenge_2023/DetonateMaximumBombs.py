'''
Q2101. Description: You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.
'''

from collections import defaultdict

class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        answer = 0
        graph = defaultdict(list)
        n = len(bombs)

        # Store bomb location and power in graph
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                xi, yi, ri = bombs[i]
                xj, yj, rj = bombs[j]

                # If i can detonate j, add node i -> node j edge
                if ri ** 2 >= (xi - xj) ** 2 + (yi - yj) ** 2:
                    graph[i].append(j)

        def DFS(cur, visited):
            # Visit all neighbours of node
            visited.add(cur)
            for nei in graph[cur]:
                if nei not in visited:
                    DFS(nei, visited)
            return len(visited)
        
        for i in range(n):
            visited = set()
            answer = max(answer, DFS(i, visited))
        
        return answer
