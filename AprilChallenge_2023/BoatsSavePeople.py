'''
Q881. Description: You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
'''

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        # Binary search on sorted array
        people.sort()
        start = 0
        end = len(people) - 1
        count = 0
        
        while start <= end:
            # Persons can be put in same boat
            if people[start] + people[end] <= limit:
                start += 1
                end -= 1
            else:
                # end person cannot form a pair
                end -= 1
            count += 1
        return count
                