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
    int ans =0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
           return 0 ;
        }
        fun(root,0);
        return ans; 
    }
    void fun(TreeNode* curr, int sum){
      if (curr == NULL){
          return ;
          }
        
        if ( curr -> left == NULL and curr -> right == NULL ) {
            ans += sum + curr->val;
            return ;
            }
        
        fun(curr->left, (sum + curr->val)*10);
       fun(curr->right, (sum + curr->val)*10);
        
       

    }
    
};