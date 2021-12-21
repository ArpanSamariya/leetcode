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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ret;
        if(root == NULL)return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        int sz;
        
        while(!q.empty()){
            sz = q.size();
            vector<int> v;
            for(int i = 0; i < sz; i++){
                
                tmp = q.front();
                v.push_back(tmp->val);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            ret.push_back(v);
           }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};