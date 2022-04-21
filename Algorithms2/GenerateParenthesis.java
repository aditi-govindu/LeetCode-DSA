/*
Q22. Description: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example: n = 3, ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        // Return no parentheses for empty n
        if(n == 0)
            ans.add("");
        else
        {
            // For starting bracket at 0, closing must be at 2c + 1
            for(int i = 0; i < n; i++)
            {
                // Recursively generate all opening left brackets '(' then right ')'
                for (String left: generateParenthesis(i))
                    for (String right: generateParenthesis(n-1-i))
                        ans.add("(" + left + ")" + right);
            }
        }
        return ans;
    }
}