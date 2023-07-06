class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0,j=0;
        int sum=0;
        int len=INT_MAX;
        while(j<nums.size()){
            
            sum+= nums[j];
            if(sum>=target){
                
    //          len=min(len,j-i+1);
    
                while(sum>=target){
                    
                    if(sum>=target) len=min(len,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
                
            
        }
        return len==INT_MAX ? 0 :len;
    }
};