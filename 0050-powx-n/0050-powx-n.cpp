class Solution {
public:
    double myPow(double x, int n) {
        
        
        double ans=1.0;
        
        long  p=abs(n);
    
        while(p>0){
            
            if(p%2==0){
                p=p/2;
                x=x*x;
                
            }
            else{
                p--;
                ans*=x;
            }
        }
        
        if(n<0) return 1/ans;
        return ans;
    }
};