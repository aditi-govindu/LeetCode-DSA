'''
Q947. Description: On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
'''
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        points = {(i, j) for i, j in stones}
        rocks = 0
        rows = defaultdict(list)
        cols = defaultdict(list)
        
        def dfs(i, j):
            points.discard((i,j))
            for y in rows[i]:
                if (i, y) in points:
                    dfs(i, y)
            for x in cols[j]:
                if(x, j) in points:
                    dfs(x, j)
        
        for i, j in stones:
            rows[i].append(j)
            cols[j].append(i)
        
        for i, j in stones:
            if (i, j) in points:
                dfs(i, j)
                rocks += 1
        
        return len(stones) - rocks
            
            