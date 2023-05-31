/*
Q1557. Description: Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,list<int>> adj;
        vector<int> temp(n,0),ans;
        for(auto i:edges)
        {
            // Store adjacent vertices and increment path by 1
            adj[i[0]].push_back(i[1]);
            temp[i[1]]++;
        }
        for(int i=0;i<n;i++) 
            if(temp[i] == 0) 
                ans.push_back(i);
        return ans;
    }
};