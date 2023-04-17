'''
Q1901. Description: A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
'''

class Solution(object):
    def findPeakGrid(self, mat):
        startCol = 0
        endCol = len(mat[0])-1
       
        while startCol <= endCol:
            maxRow = 0
            midCol = (endCol+startCol)//2
            
            for row in range(len(mat)):
                maxRow = row if (mat[row][midCol] >= mat[maxRow][midCol]) else maxRow
            
            leftIsBig = midCol-1 >= startCol  and  mat[maxRow][midCol-1] > mat[maxRow][midCol]
            rightIsBig = midCol+1 <= endCol    and  mat[maxRow][midCol+1] > mat[maxRow][midCol]
            
            if (not leftIsBig) and (not rightIsBig):   # we have found the peak element
                return [maxRow, midCol]

            # if rightIsBig, element in 'right' that is bigger than elements in the midCol 
            elif rightIsBig: 
                # 'midCol' cannot have 'peakPlane'            
                startCol = midCol+1    
            else:           
                endCol = midCol-1
                
        return []