'''
Q149. Description: Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
'''
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        def max_points_line_i(i):
            # For common i, find points on same line
            
            def coprime_slope(x1, x2, y1, y2):
                # Use co-prime numbers to represent slope
                delta_x = x2 - x1
                delta_y = y2 - y1
                if(delta_x == 0):
                    return (0,0)
                elif(delta_y == 0):
                    return (sys.maxsize(), sys.maxsize())
                elif delta_x < 0:
                    # Convert numbers to positive to compute GCD for coprimes
                    delta_x, delta_y = -delta_x, -delta_y
                gcd = math.gcd(delta_x, delta_y)
                slope = (delta_x/gcd, delta_y/gcd)
                return slope
            
            def add_line(i, j, count, duplicates):
                x1 = points[i][0]
                x2 = points[j][0]
                y1 = points[i][1]
                y2 = points[j][1]
                # Add duplicate point
                if x1 == x2 and y1 == y2:
                    duplicates += 1
                elif y1 == y2:
                    nonlocal horizontal_lines
                    horizontal_lines += 1
                    count = max(horizontal_lines, count)
                else:
                    slope = coprime_slope(x1, x2, y1, y2)
                    lines[slope] = lines.get(slope, 1) + 1
                    count = max(lines[slope], count)
                return count, duplicates
            # Initialize points passing through point i
            lines, horizontal_lines = {}, 1
            count = 1
            duplicates = 0
            # Update loop based on no. of times line passes through point i and j
            for j in range(i+1, n):
                count, duplicates = add_line(i, j, count, duplicates)
            return count + duplicates
        
        # If less than 3 points, all in same line
        n = len(points)
        if n < 3:
            return n
        
        max_count = 1
        for i in range(n-1):
            max_count = max(max_points_line_i(i), max_count)
        return max_count
            