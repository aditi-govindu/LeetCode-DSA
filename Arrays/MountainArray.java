/*
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
arr.length >= 3
*/

// Q9. Valid Mountain array
class Solution {
    public boolean validMountainArray(int[] arr) {
        int h = arr.length - 1;
        // No mountain array for less than 2 elements
        if(h < 2)
            return false;
        int j = 0;
        
        // Elements to the left must strictly be less than neighbour
        while(j+1 < arr.length && arr[j] < arr[j+1])
        {
            j++;
        }
        
        // Maximum element cannot be at start or end of array
        if(j == 0 || j == h)
            return false;
        
        // Elements to the right must strictly be greater than neighbour
        while(j+1 < arr.length && arr[j] > arr[j+1])
        {
            j++;
        }
        
        // Return true if all elements were visited
        return j == h;
    }
}