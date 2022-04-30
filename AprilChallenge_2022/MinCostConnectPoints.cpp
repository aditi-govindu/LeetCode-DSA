/*
Q1584. Description: You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
*/

/* KRUSKAL ALGORITHM */
class UnionFind
{
public:
    vector<int> group;
    vector<int> rank;
    
    // Parameterized constructor to initialize the varaibles
    UnionFind(int size)
    {
        group = vector<int>(size);
        rank = vector<int>(size);
        for(int i = 0; i < size; i++)
            group[i] = i;
    }
    
    // Find group for node
    int find(int node)
    {
        if(group[node] != node)
            group[node] = find(group[node]);
        return group[node];
    }
    
    // union1 function is used to merge nodes with same rank
    bool union1(int node1, int node2)
    {
        int group1 = find(node1);
        int group2 = find(node2);
        
        // If in same group, return no union
        if(group1 == group2)
            return false;
        if(rank[group1] > rank[group2])
            group[group2] = group1;
        else if(rank[group1] < rank[group2])
            group[group1] = group2;
        else
        {
            group[group1] = group2;
            rank[group2] += 1;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> allEdges;
        
        // Store all edges in current graph
        for(int i =0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                // Calculate Manhattan distance between current node(i) and next node(j)
                int weight = abs(points[i][0] - points[j][0]) + 
                             abs(points[i][1] - points[j][1]);
                allEdges.push_back({weight, {i,j}});
            }
        }
        // Sort edges in increasing order of weights
        sort(allEdges.begin(), allEdges.end());
        
        int mstCost = 0;
        int edgesUsed = 0;
        UnionFind uf(n);
        
        for(int i = 0; i < allEdges.size() && edgesUsed < n-1; ++i)
        {
            int node1 = allEdges[i].second.first;
            int node2 = allEdges[i].second.second;
            int weight = allEdges[i].first;
            
            // If nodes are joined to form a path, add edge cost to minimum spanning tree
            if(uf.union1(node1, node2))
            {
                mstCost += weight;
                edgesUsed++;
            }
        }
        return mstCost;
    }
};