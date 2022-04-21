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