class Solution {
    
    
public:
    int solve(string &s1,string &s2,int n ,int m, int i,int j,vector<vector<int>>&dp){
        
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans=(s1[i]-0)+solve(s1,s2,n,m,i+1,j+1,dp);
        }
        else{
            ans=max(solve(s1,s2,n,m,i+1,j,dp),solve(s1,s2,n,m,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        string s="";
        int total=0;
        for(auto i:s1){
            total+=(i-0);
        }
        
        for(auto i:s2){
            total+=(i-0);
        }
        cout<<total<<endl;
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=solve(s1,s2,n,m,0,0,dp);
        // cout<<ans<<endl;
        return total-2*ans;
    }
};