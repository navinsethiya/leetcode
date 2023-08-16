class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int i=0,j=0;
        deque<int>ds;
        while(j<n){
            if(j-i<k){
                
                if(ds.empty() || ds.back()>=nums[j]){
                    ds.push_back(nums[j]);
                }
                else{
                    while(!ds.empty() && ds.back()<nums[j]){
                        ds.pop_back();
                    }
                    ds.push_back(nums[j]);
                }
                j++;
            }
            else{
                ans.push_back(ds.front());
                if(nums[i]==ds.front()) ds.pop_front();
                i++;
                 
            }
            
        }
        ans.push_back(ds.front());
        return ans;
    }
};