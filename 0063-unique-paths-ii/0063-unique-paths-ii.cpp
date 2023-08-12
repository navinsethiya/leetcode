class Solution {
    
    
    
    
    int solve(vector<vector<int>>&grid,int r,int c,int n,int m,vector<vector<int>>&dp){
        
        
        if(r==n-1 && c==m-1) {
            
            return 1 ;
        }
        if(r==n || c==m || grid[r][c]==1) return 0;
        
        if(dp[r][c]!=-1) return dp[r][c];
        int down=0,right=0;
        
       
        down=solve(grid,r+1,c,n,m,dp);
        right=solve(grid,r,c+1,n,m,dp);
        
        
        return dp[r][c]=down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        
        int n=grid.size();
        int m=grid[0].size();
       
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0; 
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(grid,0,0,n,m,dp);
    }
};