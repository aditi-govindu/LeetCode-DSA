/*
Q2305. Description: You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.
*/

class Solution {
public:
    int answer = INT_MAX;

    void DFS(vector<int>& distribute, vector<int>& cookies, int index, int maxi)
    {   
        // If end of cookies reached, check if minimal distribution possible
        if(index >= cookies.size())
        {
            answer = min(answer, maxi);
            return;
        }

        int c = cookies[index];
        for(int i = 0; i < distribute.size(); i++)
        {
            // Distribute cookie and recursively search next distribution
            distribute[i] += c;
            DFS(distribute, cookies, index + 1, max(maxi, distribute[i]));
            // Backtrack distribution, if needed
            distribute[i] -= c;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> distribute(k, 0);
        DFS(distribute, cookies, 0, 0);
        return answer;
    }
};