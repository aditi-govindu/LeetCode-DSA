/*
Q934. Description: You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
*/

class Solution {
public:
    void fillQueue(queue<pair<int,int>>&helper, vector<vector<int>>& grid , int i, int j, int n, vector<vector<bool>>&visited)
    {    
        visited[i][j]=true;
        helper.push({i,j});

        while(!helper.empty())
        {
            pair<int,int>front=helper.front();
            helper.pop();
            int x=front.first;
            int y=front.second;

            if(x+1<n && visited[x+1][y]==false && grid[x+1][y]==1)
            {
                helper.push({x+1,y});
                visited[x+1][y]=true;
            }

            if(x-1>=0 && visited[x-1][y]==false && grid[x-1][y]==1)
            {
                helper.push({x-1,y});
                visited[x-1][y]=true;
            }

            if(y+1<n && visited[x][y+1]==false && grid[x][y+1]==1)
            {
                helper.push({x,y+1});
                visited[x][y+1]=true;
            }

            if(y-1>=0 && visited[x][y-1]==false && grid[x][y-1]==1)
            {
                helper.push({x,y-1});
                visited[x][y-1]=true;
            }
            
        }
        return;
    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>>pq;

        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        bool flag=false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && flag==false)
                {
                    fillQueue(pq,grid,i,j,n,visited);
                    flag=true;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==true)
                    pq.push({i,j});
            }
        }

        int ans=0;

        while(!pq.empty())
        {
            int size=pq.size();
            while(size--)
            {
                pair<int,int> front=pq.front();
                int x=front.first;
                int y=front.second;
                pq.pop();

                if(x+1<n && visited[x+1][y]==false)
                {
                    if(grid[x+1][y]==1)
                        return ans;
                    else
                    {
                        pq.push({x+1,y});
                        visited[x+1][y]=true;
                    }
                }

                if(x-1>=0 && visited[x-1][y]==false)
                {
                    if(grid[x-1][y]==1)
                        return ans;
                    else
                    {
                        pq.push({x-1,y});
                        visited[x-1][y]=true;
                    }
                }

                if(y+1<n && visited[x][y+1]==false)
                {
                    if(grid[x][y+1]==1)
                        return ans;
                    else
                    {
                        pq.push({x,y+1});
                        visited[x][y+1]=true;
                    }
                }

                if(y-1>=0 && visited[x][y-1]==false)
                {
                    if(grid[x][y-1]==1)
                        return ans;
                    else
                    {
                        pq.push({x,y-1});
                        visited[x][y-1]=true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};