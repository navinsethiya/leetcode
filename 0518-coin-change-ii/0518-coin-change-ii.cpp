class Solution {
    
    
//     int solve(int x, vector<int>& coins,int i,vector<vector<int>>&dp){
        
        
//         //base case

        
//         if(i<0){
//             if(x==0) return 1;
//             return 0;
//         }
        
//         if(dp[i][x]!=-1) return dp[i][x];
        
//         int notake=solve(x,coins,i-1,dp);
//         int take=0;
//         if(x>=coins[i]) take=solve(x-coins[i],coins,i,dp);
        
        
//         return dp[i][x]=take+notake;
        
//     }
public:
    int change(int amount, vector<int>& coins){
//         int n=coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        
       
          
//         solve(amount,coins,n-1,dp);
//         return dp[n-1][amount]==0? 0 : dp[n-1][amount];
        
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        
       //base case
        for(int t=0;t<=amount;t++){  //single element left
            dp[0][t]=((t%coins[0])==0);
        }  
        
        
        for(int i=1;i<n;i++){
            
            for(int t=0;t<=amount;t++){
                
                int notake=dp[i-1][t];
                int take=0;
                if(t>=coins[i]) take=dp[i][t-coins[i]];
        
        
                dp[i][t]=take+notake;
            }
        }
        
        return dp[n-1][amount]==0? 0 : dp[n-1][amount];
    }
};
