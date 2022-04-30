/*
Q14. Description: Write a function to find the longest common prefix string amongst an array of strings.If there is no common prefix, return an empty string "".
*/
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0)
            return "";
        String word = strs[0];
        // Horizontally scan all strings in list, pairwise
        for(int i = 1; i < strs.length; i++)
        {
            // Compare string to its nearest neighbour and append identical characters
            while(strs[i].indexOf(word) != 0)
            {
                word = word.substring(0, word.length() - 1);
                if(word.isEmpty())
                    return "";
            }
        }
        return word;
    }
}