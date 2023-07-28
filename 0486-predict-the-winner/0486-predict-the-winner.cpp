class Solution {
    int dp[21][21][2];
    int solve(vector<int>& nums,int i,int end,int turn){
        if(i>end) {
             return 0;
        }
        if(dp[i][end][turn]!=-1) return dp[i][end][turn];
        if(turn==1){

             return dp[i][end][turn]=max(nums[i]+solve(nums,i+1,end,0) , nums[end]+solve(nums,i,end-1,0));
        }
        else{
             return dp[i][end][turn]=min(solve(nums,i+1,end,1) ,solve(nums,i,end-1,1));
        
        }
    }
     
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        long long  total=0;
        for(auto i:nums){
            total+=i;
        }
        int turn=1;
        
        int p1=solve(nums,0,n-1,turn);
        total-=p1;
        return p1>=total;
    }
    
};