/*
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
*/
// Q4. Duplicate zeros in an array, keeping length the same
class Solution {
    public void duplicateZeros(int[] arr) {
        int len = arr.length;
        // Store copy of original array to modify
        int[] buff = new int[len];
        
        int i = 0;
        int k = 0;
        
        while(k < len){
            // Copy elements
            buff[k] = arr[i];
            // If element is zero, set next neighbour to 0 while length of array not exceeded
            if(buff[k] == 0 && k < len-1){
                buff[++k] = 0;
            }
	// Go to next element in both arrays
            i++;
            k++;
        }
        // Replace new array in arr
        for(int j = 0; j < len; j++){
            arr[j] = buff[j];
        }
    }
}