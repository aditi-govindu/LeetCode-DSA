/*
Q1857. Description: There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
*/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto &e: edges)
        {
            // Calculate indegree for every node
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        // Track maximum frequencies of colors. a -> 0, b -> 1 ... z -> 25
        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            // Store vertices with indegree 0
            if(indegree[i] == 0)
                q.push(i);
        }

        int ans = 0;
        int seen = 0;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            // Increment frequency of node color by 1
            ans = max(ans, ++count[u][colors[u] - 'a']);
            seen++;

            for(auto &neighbour: adj[u])
            {
                // Update neighbours that use current path
                for(int i = 0; i < 26; i++)
                    count[neighbour][i] = max(count[neighbour][i], count[u][i]);

                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return seen < n ? -1 : ans;
    }
};