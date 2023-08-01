'''
Q735. Description: We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
'''

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []
        for rock in asteroids:
            # Rocks moving in the same direction, break each other
            while result and rock < 0 < result[-1]:
                if result[-1] < -rock:
                    result.pop()
                    continue
                # Remove last small rock is it is -previous one
                elif result[-1] == -rock:
                    result.pop()
                break
            else:
                result.append(rock)
        return result