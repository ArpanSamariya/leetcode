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
    bool isSame(TreeNode* left , TreeNode* right){
           
            if(left == NULL && right == NULL)return true;
            if(left == NULL && right != NULL || right==NULL && left != NULL)return false;
        
            // && left->left==right->right && left->right == right->left)
            bool n1 = isSame(left->left,right->right);
            bool n2 = isSame(left->right, right->left);
            bool n3 = (left->val == right->val);
            return (n1&&n2)&&n3;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        // TreeNode* leftSubTree = root->left;
        // TreeNode* rightSubTree = root->right;
        // if(leftSubTree->left == rightSubTree->right && leftSubTree->right == rightSubTree->left) ; 
        if(root == NULL)return true;
        return isSame(root->left, root->right);
    }
};