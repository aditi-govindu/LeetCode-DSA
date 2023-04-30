/*
Q2390. Description: You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
*/

class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> st;
        string ans;

        for(int i = 0; i < s.length(); i++)
        {
            // Push letters on stack
            if(s[i] <= 'z' && s[i] >= 'a')
                st.push(s[i]);
            else
            {
                // Pop when * is seen
                if(s[i] == '*')
                    st.pop();
            }
        }
        while(!st.empty())
        {
            // Get stack contents and reverse to get final string
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};