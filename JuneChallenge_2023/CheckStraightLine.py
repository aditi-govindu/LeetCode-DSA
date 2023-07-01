'''
Q1232. Description: You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
'''

class Solution:
    def checkStraightLine(self, points: List[List[int]]) -> bool:
        ax, ay = points[0][0], points[0][1]
        bx, by = points[1][0], points[1][1]

        # If slopes are unequal, return False
        for cx, cy in points[2:]:
            if (cy - by) * (bx - ax) != (by - ay) * (cx - bx):
                return False
        return True