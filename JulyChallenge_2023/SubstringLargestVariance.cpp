/*
Q2272. Description: The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    int largestVariance(string s) 
    {
        // Hashmap of letter frequency in s
        vector<int> counter(26, 0);
        for(char ch: s)
            counter[ch - 'a']++;
        
        int globalMax = 0;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                // Both major and minor should not appear in same substring
                if(i == j || counter[i] == 0 || counter[j] == 0)
                    continue;
                
                // Store maximum variance = major - minor
                char major = 'a' + i;
                char minor = 'a' + j;
                int majorCount = 0;
                int minorCount = 0;

                // Minor of rest of s
                int restMinor = counter[j];

                for(char ch: s)
                {
                    if(ch == major)
                        majorCount++;
                    if(ch == minor)
                    {
                        minorCount++;
                        restMinor--;
                    }

                    // If atleast 1 minor exists, update variance or local_max
                    if(minorCount > 0)
                        globalMax = max(globalMax, majorCount - minorCount);

                    // Discard previous string if atleast 1 remaining minor found
                    if(majorCount < minorCount && restMinor > 0)
                    {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }
        return globalMax;        
    }
};