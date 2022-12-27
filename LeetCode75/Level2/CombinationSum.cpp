/*
Description: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
public:
    void Sum(vector<int>& candidates, int target, 
             vector<vector<int> >& res, vector<int>& r, int i)
    {
        if(target == 0)
        {
            // Found a valid combination, add to res
            res.push_back(r);
            return;
        }
        while(i < candidates.size() && target-candidates[i] >= 0)
        {
            // If item can contribute to solution, add it to r
            r.push_back(candidates[i]);
            Sum(candidates,target - candidates[i],res,r,i);
            ++i;
            // Backtrack and remove element from solution set
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort list is ascending order
        sort(candidates.begin(), candidates.end());
        vector<int> r;
        vector<vector<int> > res;
        Sum(candidates,target,res,r,0);
        return res;
        
    }
};