// Q8. Search for double value in array
class Solution {
    public boolean checkIfExist(int[] arr) {
        for(int i = 0; i < arr.length; i++)
        {
            for(int j = 0; j < arr.length; j++)
            {
                // Not same index
                if(i != j)
                {
                    // If current element = 2(Previously seen) or vice versa, return true
                    if(arr[i] == (2*arr[j]))
                        return true;
                }
            }
        }
        return false;
    }
}