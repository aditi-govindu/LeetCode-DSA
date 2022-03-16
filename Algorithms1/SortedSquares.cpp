// Q977. Squares of sorted array - C++ is faster than Python
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            // Power function returns double value in C++, so we add 0.9 to get number
            nums[i] = (int)(pow(nums[i], 2) + 1e-9);
        }
        // Sort using in built function
        sort(nums.begin(), nums.end());
        return nums;
    }
};