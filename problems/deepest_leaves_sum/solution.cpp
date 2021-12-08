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
    map<int,int> mp;
    int deepestLeavesSum(TreeNode* root) {
        helper(root,0);
        return mp.rbegin()->second;
    }
    void helper(TreeNode* root, int h){
        
        if(!root) return;
        mp[h] += root->val;
        helper(root->left,h+1);
        helper(root->right,h+1);
    }
    
};