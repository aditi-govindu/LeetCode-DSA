/*
Q1488. Description: Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.
*/

class Solution 
{
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        vector<int> res(rains.size(),-1);
        unordered_map<int, int> m;
        set<int> zero;
        for(int i =0; i < rains.size(); ++i)
        {
            // Keep track of filled lakes
            if(rains[i] == 0)
            {
                zero.insert(i);
                res[i] = 1;
            }
            else
            {
                if(m.count(rains[i]))
                {
                    // Try to empty last filled lake
                    int lastIndex = m[rains[i]];
                    auto zeroIndex = zero.upper_bound(lastIndex);
                    // Unable to empty any lake
                    if(zeroIndex == zero.end())
                        return {};
                    res[*zeroIndex] = rains[i];
                    zero.erase(zeroIndex);
                }
                m[rains[i]] = i;
            }
        }
        return res;
    }
};