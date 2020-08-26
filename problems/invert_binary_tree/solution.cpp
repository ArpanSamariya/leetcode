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
    
    TreeNode* invertTree(TreeNode* root) {
// Recursive
//         if(root == NULL)
//             return NULL;
//         if(root->left == NULL and root->right == NULL){
//             return root;
//         }
        
//         TreeNode *left , *right;
//         left = invertTree(root->left);
//         right = invertTree(root->right);
//         root->left = right;
//         root->right = left;
//         return root;

//Iterative
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL)
            return NULL;
        while(!q.empty()){
            TreeNode *curr, *temp, *left, *right;
            curr = q.front();
            q.pop();
            // if(curr != NULL){
            left = curr->left;
            right = curr->right;
            temp = left;
            curr->left = right;
            curr->right = temp;
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
            // }
            
        }
        return root;
    }
};