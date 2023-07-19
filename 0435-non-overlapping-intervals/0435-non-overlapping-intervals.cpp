class Solution {
    
    
    static bool compare(vector<int>& e1,vector<int>& e2) {
    return e1[1] < e2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),compare);
        int ans=0;
        int end=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<end) ans++;
            else end=intervals[i][1];
        }
        return ans;
    }
};