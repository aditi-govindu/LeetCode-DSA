#include <ctype.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        int i = 0;
        // Iterate over strings in array
        for(string str : ops)
        {
            // If string is a digit, convert to int and add to stack
            if(isdigit(str[0]) || str[0] == '-')
                s.push_back(stoi(str));
            // Pop number from stack
            else if(str[0] == 'C')
                s.pop_back();
            // Duplicate element at top and push
            else if(str[0] == 'D')
                s.push_back(2*s[i]);
            // Add top 2 elements and push result
            else if(str[0] == '+')
                s.push_back(s[i] + s[i-1]);
            // i keeps track of top of stack
            i = s.size() - 1;
        }
        // Return sum of stack elements
        return accumulate(s.begin(), s.end(), 0);
    }
};