'''
Q706. Description: Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

* MyHashMap() initializes the object with an empty map.
* void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
* int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
* void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
'''

class MyHashMap:

    def __init__(self):
        # Initialize bucket list to empty values
        self.bucket_size = 1000
        self.bucket = [[] for i in range(self.bucket_size)]
    
    def assign(self, key):
        return self.bucket[key % self.bucket_size]
    
    def find(self, bucket, key):
        # If key found in bucket, return index
        for i in range(len(bucket)):
            if bucket[i][0] == key:
                return i
        return -1
            
    def put(self, key: int, value: int) -> None:
        bucket = self.assign(key)
        node = self.find(bucket, key)
        # If node found, update value to new value. Else, add as new key
        if node != -1:
            bucket[node][1] = value
        else:
            bucket.append([key, value])

    def get(self, key: int) -> int:
        bucket = self.assign(key)
        node = self.find(bucket, key)
        # If node = -1, it is not found.
        if node == -1:
            return -1
        return bucket[node][1]
        
    def remove(self, key: int) -> None:
        bucket = self.assign(key)
        node = self.find(bucket, key)
        if node == -1:
            return 
        del bucket[node]

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)