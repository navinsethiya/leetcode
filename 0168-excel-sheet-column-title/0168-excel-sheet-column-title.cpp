class Solution {
public:
    string convertToTitle(int c) {
        
    
    string ans="";
    while(c){
        c-= 1;
        char x='A' + c % 26;
        ans=x+ans;
        c/= 26;
    }

    return ans;
}
};