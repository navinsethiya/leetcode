class Solution {
    int dp[301];
    int solve(string &s,int i,unordered_map<string,int>&mp){
        if(i==s.size()) return 1;
        
        if(dp[i]!=-1) return dp[i];
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(mp.find(temp)!=mp.end())
                if(solve(s,j+1,mp)) return 1;
        }
            
        return dp[i]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int>mp;
        for(auto i:wordDict){
            mp[i]++;
        }
        memset(dp,-1,sizeof(dp));
        return solve(s,0,mp);
    }
};