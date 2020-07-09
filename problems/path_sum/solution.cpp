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
    
    bool findSum(TreeNode* root, int sum, int abhitk){
        if(root == NULL)return false;
        
        if(abhitk+root->val == sum && root->left == NULL && root->right == NULL)return true;
        
        bool left = findSum(root->left, sum, abhitk+root->val);
        bool right = findSum(root->right, sum, abhitk+root->val);
        
        return left || right;        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return findSum(root,sum,0);
    }
};