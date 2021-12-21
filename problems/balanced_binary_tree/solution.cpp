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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
         return height(root) != -1;
    }
    
//     bool helper(TreeNode* root){
        
//         if(root == NULL)return true;
//         bool current = abs(height(root->left) - height(root->right)) < 2 ;
        
//         return helper(root->left) and current and helper(root->right);
        
//     }
    int height(TreeNode* root){
        
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == -1 || rh == -1)return -1;
        if(abs(lh-rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
    
};