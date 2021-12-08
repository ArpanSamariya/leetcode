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
    int ans = 0;
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
    
    int helper(TreeNode* root){
        
        if(!root) return 0;
        int right = helper(root->right);
        int left = helper(root->left);
        ans = ans + abs( right - left );
        
        return right + left + root->val;

    }
};