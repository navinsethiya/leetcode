/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    unordered_map<TreeNode*,TreeNode*>parent;
    unordered_map<TreeNode*,int>vis;
    void findParent(TreeNode *root){
        if(root==NULL){
            return;
        }
        
        
        
        if(root->left) {
            parent[root->left]=root;
            findParent(root->left);
        }
        
        
        if(root->right) {
            parent[root->right]=root;
            findParent(root->right);
        }
    }
    void solve(TreeNode* root, int k,vector<int>&ans){
        if(root==NULL) return;
        if(vis[root]) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        vis[root]++;
        if(root->left){
    
            solve(root->left,k-1,ans);
        }
        
        if(root->right){
        
            solve(root->right,k-1,ans);
        }
        
        if(parent[root]){
            
            solve(parent[root],k-1,ans);
        }
        
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>ans;
        findParent(root);
        
        
        solve(target,k,ans);
        return ans;
    }
};