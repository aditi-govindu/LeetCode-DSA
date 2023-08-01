/*
Q859. Description: Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        // Unequal length strings can never be made equal
        if (s.length() != goal.length())
            return false;
        
        if(s == goal)
        {
            // If same characters present, swap to make strings equal
            vector<int> frequency(26, 0);
            for(int i = 0; i < s.length(); i++)
            {
                frequency[s[i] - 'a'] += 1;
                if(frequency[s[i] - 'a'] == 2)
                    return true;
            }
            return false;
        }

        int firstIndex = -1;
        int secondIndex = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i])
            {
                // Find no. of indexes that differ. If 3 or more, never possible with 1 swap
                if(firstIndex == -1)
                    firstIndex = i;
                else if(secondIndex == -1)
                    secondIndex = i;
                else
                    return false;
            }
        }
        // If only 1 index differs, equal not possible with 1 swap
        if(secondIndex == -1)
            return false;

        // Exactly 2 indexes differ -> Strings are equal
        return s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex];
    }
};