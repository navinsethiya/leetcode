class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        
        vector<long long>v;
        int n=weights.size();
        for(int i=0;i<n-1;i++){
            long long s=weights[i]+weights[i+1];
            v.push_back(s);
        }
        
        sort(v.begin(),v.end());
        long long mini=0,maxi=0;
        
        for(int i=0;i<k-1;i++){
            mini+=v[i];
             maxi+=v[n-2-i];
        }
        
        
        return maxi-mini;
    }
};