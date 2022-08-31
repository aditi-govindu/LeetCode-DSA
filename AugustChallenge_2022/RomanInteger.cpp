/*
Q13. Description: Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M. Given a roman numeral, convert it to an integer.

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
*/

#include <map>

class Solution 
{
public:
    int romanToInt(string s) 
    {
        map<char, int> roman = {{'I', 1},{'V',5},{'X',10},{'L',50}, {'C',100},{'D',500}, {'M',1000}};
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int val = roman[s[i]];
            if(i+1 < s.length())
            {
                if(val < roman[s[i+1]])
                    result -= val;
                else
                    result += val;
            }
            else
                result += val;
        }
        return result;
    }
};