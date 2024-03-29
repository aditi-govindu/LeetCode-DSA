/*
Q839. Description: Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
*/

class Solution 
{
public:
    // Depth first search for non visited nodes close to current node
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) 
    {
        visit[node] = true;
        for (int neighbor : adj[node]) 
        {
            if (!visit[neighbor])
                dfs(neighbor, adj, visit);
        }
    }

    // Find positions of difference in both strings
    bool isSimilar(string& a, string& b) 
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) 
        {
            if (a[i] != b[i]) 
                diff++;
        }
        // Return true if strings are identical or 1 swap can be done to get the other
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        vector<vector<int>> adj(n);
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                // If strings are anagrams, store as adjacent connected components
                if (isSimilar(strs[i], strs[j])) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visit(n);
        int count = 0;

        // Count the number of connected components.
        for (int i = 0; i < n; i++) 
        {
            if (!visit[i]) 
            {
                dfs(i, adj, visit);
                count++;
            }
        }
        return count;
    }
};