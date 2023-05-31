'''
Q705. Description: Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
'''

class MyHashSet:
    def __init__(self):
        # Initialize set with maximum limit
        self.set = [False] * (10 ** 6 + 1)
        
    def add(self, key: int) -> None:
        # Assign key to True
        self.set[key] = True

    def remove(self, key: int) -> None:
        # Assign key to false, indicating deleted
        self.set[key] = False

    def contains(self, key: int) -> bool:
        # Return values of key, true means found
        return self.set[key]

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)