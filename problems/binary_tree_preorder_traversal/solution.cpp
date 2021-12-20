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
//     vector<int> ret;
//     vector<int> preorderTraversal(TreeNode* root) {
        
//         if(root == NULL){
//             return ret;
//         }
//         helper(root);
//         return ret;
//     }
//     void helper(TreeNode* root){
        
//         if(root == NULL)return;
//         ret.push_back(root->val);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//     }
// };

class Solution {
public:
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
    
        if(root == NULL)return ret;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* tmp = st.top();
            st.pop();
            ret.push_back(tmp->val);
            
            if(tmp->right){
              st.push(tmp->right);
            }
            if(tmp->left){
              st.push(tmp->left);
            }       
        }
        return ret;
    }
};
