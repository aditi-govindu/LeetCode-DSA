/*
Q547. Description: There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
    public void DFS(int[][] isConnected, boolean[] visited, int province)
    {
       if(visited[province])
           return;
        // Add province to visited list before exploring neighbours
        visited[province] = true;
        for(int i = 0; i < isConnected[province].length; i++)
        {
            // Recursively visit all provinces adjacent to current province
            if(i != province && isConnected[province][i] == 1)
                DFS(isConnected, visited, i);
        }
    }
    
    public int findCircleNum(int[][] isConnected) {
        int count = 0;
        boolean[] visited = new boolean[isConnected.length];
        for(int i = 0; i < visited.length; i++)
        {
            // If province is not visited, explore it and its neighbours
           if(!visited[i])
           {
               count++;
               DFS(isConnected, visited, i);
           }
        }
        return count;
    }
}