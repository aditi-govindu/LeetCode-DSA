/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
After doing so, return the array.
*/

// Q10. Replace element by greatest one in right half of array
class Solution {
    public int[] replaceElements(int[] arr) {
        // Set last element in right side to -1
        int maxRight = -1;
        int len = arr.length;
        
        for(int i = len-1; i>=0; i--)
        {
            int temp = maxRight;
            // Read from right to left, replace with maximum element in the right side
            if(arr[i] > maxRight)
            {
                maxRight = arr[i];
            }
            arr[i] = temp;
        }
        return arr;
    }
}