'''
Q1870. Description: You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.
'''

class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        lo, hi, n = 1, 10 ** 7 + 1, len(dist)
        
        while lo < hi:
            speed = lo + (hi - lo) // 2

            # ceil is obtained by dist + speed - 1 / speed
            need = dist[-1] / speed + sum((dist[i] + speed - 1) // speed for i in range(n - 1))

            if need > hour:
                lo = speed + 1
            else:
                hi = speed

        return -1 if lo == 10 ** 7 + 1 else lo  s