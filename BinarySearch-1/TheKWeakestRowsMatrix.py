'''
Q1337. Description: You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
'''

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        soldiers = {}

        for i in range(len(mat)):
            count = 0
            # Count no. of soldiers per row
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    count += 1

            # Store index of row : Soldier count
            soldiers[i] = count
            
        # Sort dictionary based on values
        weakest = dict(sorted(soldiers.items(), key=lambda x:x[1]))

        # Return result as top k records
        return list(weakest.keys())[:k]