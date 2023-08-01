/*
Q1601. Description: We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.

You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building from[i] to building to[i].

All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.

Return the maximum number of achievable requests.
*/

class Solution {
public:
    int answer = 0;

    void maxRequests(vector<vector<int>>& requests, vector<int>& indegree, int n, int index, int count)
    {
        if(index == requests.size())
        {
            for(int i = 0; i < n; i++)
            {
                // If indegree of any building is 0, return
                if(indegree[i])
                    return;
            }
            // Indegree not 0, initialize answer
            answer = max(answer, count);
            return;
        }
        // Consider the move from -> to and modify indegree accordingly
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;

        // Move to next request
        maxRequests(requests, indegree, n, index + 1, count + 1);

        // Backtrack to previous state before 2nd recursion
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;

        // Move to next request
        maxRequests(requests, indegree, n, index + 1, count);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        vector<int> indegree(n, 0);
        maxRequests(requests, indegree, n, 0, 0);
        return answer;   
    }
};