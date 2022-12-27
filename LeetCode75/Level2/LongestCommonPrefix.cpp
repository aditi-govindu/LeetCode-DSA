/*
Q14. Description: Write a function to find the longest common prefix string amongst an array of strings.If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size() == 0)
            return "";
        string word = strs[0];
        // Traverse through all words in list
        for(int i = 1; i < strs.size(); i++)
        {
            while(strs[i].find(word) != 0)
            {
                word = word.substr(0, word.length() - 1);
                if(word.empty())
                    return "";
            }
        }
        return word;
    }
};