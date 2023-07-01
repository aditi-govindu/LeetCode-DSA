/*
Q1569. Description: Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numOfWays(vector<int>& nums) 
    {
        int n = nums.size();
        // Use Pascal's triangle to reduce no. of times nCk is computed
        table.resize(n+1);
        for(int i = 0; i <= n; i++)
        {
            table[i] = vector<long long>(i+1, 1);
            // Store permutations or ways for each combination of n and k
            for(int j = 1; j < i; j++)
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
        }
        return (DFS(nums) - 1) % mod;
    }

    vector<vector<long long>> table;
    long long mod = 1e9 + 7;

    long long DFS(vector<int>& nums)
    {
        int m = nums.size();
        // If nodes < 3, only 1 permutation allowed
        if(m < 3)
            return 1;

        vector<int> left, right;
        for(int i = 1; i < m; i++)
        {
            // Chose first element of nums as root and reorder the elements
            // As per rules of BST where left < root and right > root
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        long long leftWays = DFS(left) % mod;
        long long rightWays = DFS(right) % mod;

        // Permutations are left options * right options * nCk
        return (((leftWays * rightWays) % mod) * table[m - 1][left.size()]) % mod;
    }
};