/*
Q1502. Description: A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());

        // Common difference must be same across all numbers in array
        int d1 = arr[1] - arr[0];
        for(int i = 1; i < arr.size() - 1; i++)
        {
            if(arr[i+1] - arr[i] != d1)
                return false;
        }
        return true;
    }
};