/*
Q1562. Description: Given an array arr that represents a permutation of numbers from 1 to n.

You have a binary string of size n that initially has all its bits set to zero. At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i] is set to 1.

You are also given an integer m. Find the latest step at which there exists a group of ones of length m. A group of ones is a contiguous substring of 1's such that it cannot be extended in either direction.

Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.
*/

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) 
    {
        int n = arr.size();
        int ans = -1;

        if(n == m)
            return n;
        
        vector<int> length(n+2, 0);
        vector<int> count(n+1, 0);

        for(int i = 0; i < n; i++)
        {
            int a = arr[i];
            int low = length[a - 1];
            int high = length[a + 1];

            int sum = low + high + 1;

            // Update length of active cells to left and right of current location
            length[a - low] = length[a + high] = sum;

            // Keep track of active sequences using a hashmap
            count[low]--;
            count[high]--;
            count[sum]++;

            // If any sequence length is greater than 0, return index
            if(count[m] > 0)
                ans = i+1;
        }
        return ans;
    }
};