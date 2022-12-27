/*
Q746. Description: You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int prev = cost[0];
        int curr = cost[1];
        
        for (int i = 2; i < cost.size(); i++) 
        {
		    int tmp = curr;
		    curr = min(prev, curr) + cost[i]; // calculates the min cost using step i
		    prev = tmp; // prev is moved forward one step
	    }
	    return min(curr, prev);
    }
};