class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
     
        // this problem can be break it down into two parts
        // first part , maximum length of  'T' which contains at most k 'F'
        //second part , maximum length of  'F' which contains at most k 'T'
        // return max(first part, second part)
        
        int left=0,right=0,n=a.size();
        int count=0,len1=0,len2=0;
        
        //first part
        while(right<n){
            
            if(a[right]=='F') {
            
                count++;
            }
            
            while(count>k){
                if(a[left]=='F') count--;
                
                left++;
            }
            
            len1=max(len1,right-left+1);
            
            right++;
        }
        
        left=0,right=0,count=0;
        // second part
         while(right<n){
            
            if(a[right]=='T') {
            
                count++;
            }
            
            while(count>k){
                if(a[left]=='T') count--;
                
                left++;
            }
            
            len2=max(len2,right-left+1);
            
            right++;
        }
        return max(len1,len2);
        
    }
};