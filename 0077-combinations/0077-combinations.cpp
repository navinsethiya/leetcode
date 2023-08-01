class Solution {
    void solve(vector<vector<int>>&ans,vector<int>&v,int n ,int k,int i){
        
        if(i==n+1){
            if(v.size()==k){
            ans.push_back(v);
        }
            return;
        }
        
        v.push_back(i);
        
        solve(ans,v,n,k,i+1);
        
        v.pop_back();
        
        solve(ans,v,n,k,i+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        
        vector<int>v;
        
        solve(ans,v,n,k,1);
        return ans;
    }
};