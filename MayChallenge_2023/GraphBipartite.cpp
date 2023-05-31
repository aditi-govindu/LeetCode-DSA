/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. 

The graph has the following properties:
* There are no self-edges (graph[u] does not contain u).
* There are no parallel edges (graph[u] does not contain duplicate values).
* If v is in graph[u], then u is in graph[v] (the graph is undirected).
* The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
Return true if and only if it is bipartite.
*/

class Solution 
{
public:
    vector<int> visited, col;
    bool DFS(int vertex, vector<vector<int>>& graph, int color)
    {
        // Set vertex as visited and color to 0
        visited[vertex] = 1;
        col[vertex] = color;
        for(int child: graph[vertex])
        {
            // For node not visited, set complimentary color to node in partition
            if(visited[child] == 0)
            {
                // If color is 0, set to 1 for node in opposite location
                if(DFS(child, graph, color^1) == false)
                    return false;
            }
            else
            {
                // If same color found in opposite set, bipartite partition failed
                if(col[child] == col[vertex])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n);
        col.resize(n);
        // Check partition for all nodes in graph
        for(int i = 0; i < n; ++i)
        {
            if(visited[i] == 0 && DFS(i, graph, 0) == false)
                return false;
        }
        return true;
    }
};