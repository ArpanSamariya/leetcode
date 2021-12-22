/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        return helper(root,p,q);
    }
    
    TreeNode* helper ( TreeNode* root, TreeNode* p, TreeNode* q){
        
       if(!root) return NULL;
        
       if(root->val == p -> val || root->val == q->val) return root;
        
       TreeNode* l = lowestCommonAncestor(root->left, p, q);
           
        TreeNode* r = lowestCommonAncestor(root->right, p , q);
        
        if(l == NULL and r == NULL) return NULL;
        if(l == NULL || r == NULL){
            if(l != NULL) return l;
            return r;
        }
        return root;
    }
    
    
};