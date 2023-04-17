/*
Q1552. Description: In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.
*/

class Solution 
{
public:
    int timeTaken(vector<int>& position, int k, int mid)
    {
        int x = position[0];
        int c = 1;

        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - x >= mid)
            {
                c++;
                x = position[i];
            }
            if(c == k)
                return 1;
        }
        return 0;
    }

    int maxDistance(vector<int>& position, int m) 
    {
        int low = 1;
        sort(position.begin(), position.end());
        int high = position[position.size() - 1] - position[0];
        int ans = 1;

        while(low <= high)
        {
            int mid = (low + high)/2;

            // Binary search to find least time
            if(timeTaken(position, m , mid) == 1)
            {
               ans = max(ans, mid);
               low = mid + 1; 
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};