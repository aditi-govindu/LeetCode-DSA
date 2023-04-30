/*
Q946. Description: Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> st;
        int i = 0;

        for(int j = 0; j < pushed.size(); j++)
        {
            // Push elements onto stack
            st.push(pushed[j]);

            // Pop from stack till top and new are unequal
            while(!st.empty() && st.top() == popped[i])
            {
                st.pop();
                i++;
            }
        }
        // If stack is empty, sequence is valid
        return st.empty();
    }
};