'''
Q981. Description: Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
'''

from sortedcontainers import SortedDict

class TimeMap:
    def __init__(self):
        self.key_time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # If the 'key' does not exist in dictionary.
        if not key in self.key_time_map:
            self.key_time_map[key] = SortedDict()
            
        # Store '(timestamp, value)' pair in 'key' bucket.
        self.key_time_map[key][timestamp] = value
        

    def get(self, key: str, timestamp: int) -> str:
        # If the 'key' does not exist in dictionary we will return empty string.
        if not key in self.key_time_map:
            return ""
        
        it = self.key_time_map[key].bisect_right(timestamp)
        # If iterator points to first element it means, no time <= timestamp exists.
        if it == 0:
            return ""
        
        # Return value stored at previous position of current iterator.
        return self.key_time_map[key].peekitem(it - 1)[1]