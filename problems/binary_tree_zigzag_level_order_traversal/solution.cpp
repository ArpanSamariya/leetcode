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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        TreeNode* tmp;
        int cnt = 1;
        int sz = 0;
        
        if(root == NULL) return ret;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            sz = q.size();
            vector<int> v;
            for(int i = 0; i < sz; i++){
                tmp = q.front();
                q.pop();
                if(tmp->right)q.push(tmp->right);
                if(tmp->left)q.push(tmp->left);
                v.push_back(tmp->val);
            }
            if(cnt%2){
                reverse(v.begin(), v.end());
            }
            ret.push_back(v);
            cnt++;
        }
        return ret;
    }
    
};