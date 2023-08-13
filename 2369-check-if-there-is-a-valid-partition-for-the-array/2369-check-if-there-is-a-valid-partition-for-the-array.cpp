class Solution {
public:
    
    int solve(vector<int>&dp,vector<int>&nums,int i,int n){
        
        if(i==n) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        if(i+1<n && nums[i]==nums[i+1]){
                if(solve(dp,nums,i+2,n)) return dp[i]=1;
        }
        
        if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                if(solve(dp,nums,i+3,n)) return dp[i]= 1;
        }
        
        if(i+2<n && nums[i]+1==nums[i+1] && nums[i]+2==nums[i+2]){
            
            if(solve(dp,nums,i+3,n)) return dp[i]=1;
        }
        
        return dp[i]=0;
        
        
    }
    bool validPartition(vector<int>& nums) {
        
        
        
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(dp,nums,0,n);
    }
};