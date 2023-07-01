/*
Q1575. Description: You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.

At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.

Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).

Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    int solve(vector<int>& locations, int currCity, int finish, int remainingFuel, vector<vector<int>>& memo)
    {
        // If no fuel left, return 0
        if(remainingFuel < 0)
            return 0;

        // Travel to next city with remaining fuel
        if(memo[currCity][remainingFuel] != -1)
            return memo[currCity][remainingFuel];
        
        // If finish reached, route found (1)
        int ans = currCity == finish ? 1 : 0;
        for(int nextCity = 0; nextCity < locations.size(); nextCity++)
        {
            if(nextCity != currCity)
            {
                // Recursively search for routes to travel with remaining fuel - fuel used
                ans = (ans + solve(locations, nextCity, finish, 
                                  remainingFuel - abs(locations[currCity]-locations[nextCity]),
                                 memo)) % 1000000007;
            }
        }
        return memo[currCity][remainingFuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        int n = locations.size();
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel, memo);
    }
};