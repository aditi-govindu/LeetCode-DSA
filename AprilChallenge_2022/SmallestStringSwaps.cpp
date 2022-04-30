/*
Description: You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
You can swap the characters at any pair of indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.
*/

class Solution 
{
public:
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
        
    void DFS(string& s, int vertex, vector<char>& characters, vector<int>& indices)
    {
        // Store character and vertex in 2 lists
        characters.push_back(s[vertex]);
        indices.push_back(vertex);

        visited[vertex] = true;

        // Traverse adjacent vertices
        for (int adjacent : adj[vertex]) 
        {
            if (!visited[adjacent]) 
                DFS(s, adjacent, characters, indices);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        // Build the adjacency list
        for(vector<int> edge: pairs)
        {
            int source = edge[0];
            int destination = edge[1];
            
            // Add vertices to adj, undirected edge
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }
            
            for(int i = 0; i < s.size(); i++)
            {
                // If character in string not visited, add to DFS
                if(!visited[i])
                {
                    vector<char> characters;
                    vector<int> indices;
                    DFS(s, i, characters, indices);
                    
                    // Sort lists
                    sort(characters.begin(), characters.end());
                    sort(indices.begin(), indices.end());
                    
                     // Store the sorted characters corresponding to the index
                    for (int index = 0; index < characters.size(); index++)
                        s[indices[index]] = characters[index];
                }
            }
        return s;
    }
};