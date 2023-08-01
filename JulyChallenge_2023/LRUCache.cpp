/*
Q146. Description: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

class LRUCache 
{
public:
    class Node
    {
        // Double linked list
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val)
            {
                this -> key = key;
                this -> val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> map;

    LRUCache(int capacity) 
    {
        // Initialize cache size and key-value pairs
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newNode)
    {
        // Add node to double linked list
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;

        head -> next = newNode;
        temp -> prev = newNode;
    }
    
    void deleteNode(Node* delNode)
    {
        // Remove node from double linked list
        Node* prevv = delNode -> prev;
        Node* nextt = delNode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }

    int get(int key) 
    {
        // If key exists in hashmap
        if(map.find(key) != map.end())
        {
            // Erase key value pair and remove it. Place it at end of queue
            Node* result = map[key];
            int ans = result -> val;

            map.erase(key);
            deleteNode(result);
            addNode(result);

            // Update map as recently used node
            map[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        // If key already in map, place it at the front
        if(map.find(key) != map.end())
        {
            Node* curr = map[key];
            map.erase(key);
            deleteNode(curr);
        }

        // If cache is full, remove least recently used node from end of linked list
        if(map.size() == cap)
        {
            map.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        addNode(new Node(key, value));
        map[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */