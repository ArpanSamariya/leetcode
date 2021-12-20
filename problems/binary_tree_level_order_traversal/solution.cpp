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
//     vector<vector<int>> levelOrder(TreeNode* root) {
        
//         vector<vector<int>> ret;
//         if(root == NULL){
//             return ret;
//         }
//         stack<TreeNode*> st1;
//         stack<TreeNode*> st2;
//         TreeNode* tmp;
//         vector<int> v;
//         st1.push(root);
        
//         while(!st1.empty()){
            
//             tmp = st1.top();
//             st1.pop();
//             v.push_back(tmp->val);
            
//             if(tmp->left) st2.push(tmp->left);
//             if(tmp->right)st2.push(tmp->right);
            
//             if(st1.empty()){
//                 vector<int> vi(v);
//                 ret.push_back(vi);
//                 v.clear();
//                 while(!st2.empty()){
//                     tmp = st2.top();
//                     st1.push(tmp);
//                     st2.pop();
//                 }
//             }   
//         }
//         return ret;
//     }
// };


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }
        queue<TreeNode*> q;
        TreeNode* tmp;
        q.push(root);
        int sz = 0;
        while(!q.empty()){
            sz = q.size();
            vector<int> v;
            for(int i = 0; i < sz; i++){
                
                tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
                
            }
            ret.push_back(v);
        }
        return ret;
    }
};