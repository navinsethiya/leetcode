class Solution {
    
    void solve(vector<string>&demo,string &digits,string s,int index,vector<string>&ans){
        
        if(index>=digits.size()) {
            ans.push_back(s);
            return;
        }
        
        string str=demo[digits[index]-'0'-2];
        for(int i=0;i<str.size();i++){
            
            
            s.push_back(str[i]);
            solve(demo,digits,s,index+1,ans);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<string>demo={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string s="";
        int index=0;
        
        vector<string>ans;
        solve(demo,digits,s,index,ans);
        return ans;
    }
};