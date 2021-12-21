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
// class Solution {
// public:
//     int mx = INT_MIN;
//     int maxPathSum(TreeNode* root) {
//         if(root == NULL) return 0;
//         return max(mx,helper(root));
//     }
    
//     int helper(TreeNode* root){
        
//         if(root == NULL) return 0;

//         int ls = helper(root->left);
//         int rs = helper(root->right);
        
//         if(ls != 0)
//         mx = max(ls,mx);
        
//         if(rs != 0)
//         mx = max(rs,mx);
        
//         mx = max(root->val,mx);
//         mx = max(ls+rs+root->val,mx);

//         return max({ls+root->val , rs+root->val, root->val}); 
//     }
// };

class Solution {
public:
    int mx = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        helper(root);
        return mx;
    }
    
    int helper(TreeNode* root){
        if(!root)return 0;
        int left = max(0,helper(root->left));
        int right = max(0,helper(root->right));
        
        mx = max(mx, left + right + root->val);
        
        return root->val + max(left,right);
    }
};