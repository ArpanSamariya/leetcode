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
   int ans = INT_MAX;
   int minDepth(TreeNode* root) {
        
        if(root == NULL)return 0;
        helper(root,1);
        return ans;
    }
    
    void helper(TreeNode* root, int h){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL){
            ans = min(ans,h);
        }
        helper(root->left,h+1);
        helper(root->right,h+1);
    }
};