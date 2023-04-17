'''
Q1146. Description: Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
'''

class SnapshotArray:

    def __init__(self, length: int):
        self.map = defaultdict(list)
        self.snapid = 0
    
    def set(self, index: int, val: int) -> None:
        if self.map[index] and self.map[index][-1][0] == self.snapid:
            self.map[index][-1][1] = val
            return
        self.map[index].append([self.snapid, val])

    def snap(self) -> int:
        self.snapid += 1
        return self.snapid - 1

    def get(self, index: int, snap_id: int) -> int:
        arr = self.map[index]
        left, right, ans = 0, len(arr) - 1, -1

        while left <= right:
            mid = (left + right) // 2
            if arr[mid][0] <= snap_id:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        if ans == -1: return 0
        return arr[ans][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)