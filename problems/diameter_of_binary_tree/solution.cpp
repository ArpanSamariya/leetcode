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
    int helper(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if(left + right + 1 > ans){
            ans = left + right;
        }
        return max(left,right)+1;
    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        int a = helper(root);
        return ans;
        
        
        
    }
};