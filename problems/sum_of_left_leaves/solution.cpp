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
    int sumOfLeftLeaves(TreeNode* root) {
        fun(root);
        return ans;
    }
    void fun(TreeNode* curr) {
        if(curr == NULL){
            return;
        }
        if(curr->left == NULL and curr->right == NULL){
            return;
        }
        
        if(curr->left != NULL and curr->left->left == NULL and curr->left->right == NULL){
            ans += curr->left->val;
        }
        fun(curr->left);
        fun(curr->right);
    }
    
};