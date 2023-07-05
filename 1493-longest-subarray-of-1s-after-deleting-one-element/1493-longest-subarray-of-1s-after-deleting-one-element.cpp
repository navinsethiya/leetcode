class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    
        int left=0,right=0;
        int zero=0;
        
        int ans=0;
        while(right<nums.size()){
            
            if(nums[right]==0){
                
                zero++;
                
                if(zero==2){
                    
                    
                    while(nums[left]!=0){
                        left++;
                    }
                    left++;
                    right++;
                    zero--;
                }
                else{
                   ans=max(ans,right-left);
                    right++;
                
                }
            }
            
            
            else{
                 ans=max(ans,right-left);
                right++;
            }
        }
        
        return ans;
    }
};