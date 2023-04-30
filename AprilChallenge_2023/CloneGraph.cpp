/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
Q133. Description: Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/

class Solution {
public:
    Node* DFS(Node* curr, unordered_map<Node*, Node*>& map)
    {
        vector<Node*> neighbours;
        Node* clone = new Node(curr -> val);
        map[curr] = clone;

        for(auto &it: curr -> neighbors)
        {
            if(map.find(it) != map.end())
                neighbours.push_back(map[it]);
            else
                neighbours.push_back(DFS(it, map));
        }
        clone -> neighbors = neighbours;
        return clone;
    }
    
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*, Node*>map;
        if(node == NULL)
            return NULL;
        if(node -> neighbors.size() == 0)
        {
            Node* clone = new Node(node -> val);
            return clone;
        }
        return DFS(node, map);
    }
};