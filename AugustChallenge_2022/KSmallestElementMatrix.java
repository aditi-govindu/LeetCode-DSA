/*
Q378. Description: Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).
*/

public class Solution 
{
    public int kthSmallest(int[][] matrix, int k) 
    {
        int n = matrix.length;
        // Place nodes in priority queue and return smallest value at k level of min heap
        PriorityQueue<int[]> pq = 
            new PriorityQueue<>(Comparator.comparingInt(p -> matrix[p[0]][p[1]]));
        for(int j = 0; j <= n-1; j++) 
            pq.offer(new int[] {0,j});
        for(int i = 0; i < k-1; i++) 
        {
            var p = pq.poll();
            if(++p[0] == n) 
                continue;
            pq.offer(p);
        }
        return matrix[pq.peek()[0]][pq.peek()[1]];
    }
}