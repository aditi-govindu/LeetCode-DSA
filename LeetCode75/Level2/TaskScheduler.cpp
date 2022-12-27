/*
Q621. Description: Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int len = tasks.size();
        
        unordered_map<char, int> scheduler;
        int count = 0;
        
        for(int i = 0; i < len; i++)
        {
            scheduler[tasks[i]] ++;
            count = max(count, scheduler[tasks[i]]);
        }
        int ans = (count - 1) * (n + 1);
        for(auto e : scheduler)
            if(e.second == count)
                ans ++;
        return max(len, ans);
    }
};