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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<int> ret;
        TreeNode* tmp;
        st1.push(root);
        
        if(root == NULL) return ret;
        
        while(!st1.empty()){
            tmp = st1.top();
            st1.pop();
            st2.push(tmp);
            
            if(tmp->left) st1.push(tmp->left);
            if(tmp->right) st1.push(tmp->right);
        }
        int t;

        while(!st2.empty()){
            tmp = st2.top();
            ret.push_back(tmp->val);
            st2.pop();
        }
        return ret;
    }
};