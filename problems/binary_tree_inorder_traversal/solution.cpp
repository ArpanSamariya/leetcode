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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        for( auto t = root; t != NULL; t = t->left){
            st.push(t);
        }
        while(!st.empty()){
            TreeNode* curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            
            for(auto p = curr->right; p != NULL; p = p -> left){
                st.push(p);
            }
        }
        return ans;
    }
};