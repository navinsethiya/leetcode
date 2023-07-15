class Solution {
    int maxi=0;
    int solve(vector<vector<int>>& e,vector<vector<int>>&dp,int ans,int i,int n,int k){
        
        if(i==n || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int x;
        
        for( x=i+1;x<n;x++){
            if(e[i][1]<e[x][0]) break;
        }
    
        int take =e[i][2]+solve(e,dp,ans,x,n,k-1);
        int no=solve(e,dp,ans,i+1,n,k);
    
        dp[i][k]=max(take,no);
        maxi=max(maxi,dp[i][k]);
        return dp[i][k];
        }
    
public:
    int maxValue(vector<vector<int>>& e, int k) {
        
        sort(e.begin(),e.end());
        int n=e.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans=0;
        solve(e,dp,ans,0,n,k);
        return maxi;
    }
};