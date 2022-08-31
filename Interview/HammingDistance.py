'''
Q461. Description: The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.
'''
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        binary_x = []
        binary_y = []
        # Store only 0 and 1 in binary representation of number
        for digit in bin(x):
            if digit != 'b':
                binary_x.append(digit)
        for digit in bin(y):
            if digit != 'b':
                binary_y.append(digit)
        y = len(binary_y)
        x = len(binary_x)
        # Append zeros to front of smaller array
        if x < y:
            binary_x.reverse()
            for i in range(y-x):
                binary_x.append('0')
            binary_x.reverse()
        elif x > y:
            binary_y.reverse()
            for i in range(x-y):
                binary_y.append('0')
            binary_y.reverse()
        count  = 0
        # If unequal bits found, increment count by 1
        for i in range(max(x,y)):
            if binary_x[i] != binary_y[i]:
                count+=1
        return count