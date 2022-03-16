/* Q167. Description:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialize
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> solution;
        while(start < end)
        {
            // 2 pointer approach, check if target is start + end element
            if(numbers[start] + numbers[end] == target)
            {
                solution.push_back(start+1);
                solution.push_back(end+1);
                return solution;
            }
            // Since array is sorted, increment start point for target
            else if(numbers[start] + numbers[end] < target)
            {
                start++;
            }
            else
            {
                // Decrement end pointer if sum > target
                end--;
            }
        }
        return solution;
    }
};