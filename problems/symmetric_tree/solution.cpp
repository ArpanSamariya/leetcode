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
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* l, TreeNode* r){
        
      
        if(l == NULL || r == NULL){
            return l == r;
        }
        if(l->val != r->val) return false;
        
        return helper(l->left, r->right) and helper(l->right, r->left);
        
    }
};