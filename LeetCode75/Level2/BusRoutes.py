'''
Q815. Description: You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
'''

from collections import defaultdict, deque

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        
        queue = deque()
        graph = defaultdict(set)
        routes = list(map(set, routes))
        seen, targets = set(), set()
        
        for i in range(len(routes)):
            if source in routes[i]:
                seen.add(i)
                queue.append((i, 1))
            if target in routes[i]:
                targets.add(i)
                
            for j in range(i+1, len(routes)):
                if routes[i] & routes[j]:
                    graph[i].add(j)
                    graph[j].add(i)
                    
        while queue:
            current, count = queue.popleft()
            if current in targets:
                return count
            for neighbour in graph[current]:
                if neighbour not in seen:
                    queue.append((neighbour, count + 1))
                    seen.add(neighbour)
        return -1
        