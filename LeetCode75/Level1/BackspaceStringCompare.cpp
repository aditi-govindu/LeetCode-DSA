/*
Q844. Description: Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;
        string res1 = "";
        string res2 = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
                s1.push(s[i]);
            if(s[i] == '#' && !s1.empty())
                s1.pop();
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] != '#')
                t1.push(t[i]);
            if(t[i] == '#' && !t1.empty())
                t1.pop();  
        }
        // Check if stacks are equal
        if(s1.size() != t1.size())
            return false;
        while(!s1.empty())
        {
            if(s1.top() == t1.top())
            {
                res1 = res1 + s1.top();
                res2 = res2 + t1.top();
                s1.pop();
                t1.pop();
            }
            else
                return false;
        }
        if(res1 == res2)
            return true;
        return false;
    }
};