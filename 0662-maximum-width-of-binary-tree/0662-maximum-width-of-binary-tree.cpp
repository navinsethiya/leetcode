/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL) return 0; 
        
        
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        int width=0;
        
        while(q.empty()==false){
            
            
            int size=q.size();
            int min=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                
                long long int curr_index=q.front().second-min;
                TreeNode* curr=q.front().first;
                q.pop();
                
                if(i==0) first=curr_index;
                if(i==size-1) last=curr_index;
                
                
                if(curr->left) q.push({curr->left,curr_index*2+1});
                if(curr->right) q.push({curr->right,curr_index*2+2});
            }
            width=max(width,last-first+1);
            
        }
        return width;
        
    }
};

        