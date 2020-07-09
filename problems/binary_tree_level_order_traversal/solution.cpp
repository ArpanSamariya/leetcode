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
    vector<vector<int>> vv;
    void dfs(TreeNode* root, int distance){
        if(root == NULL) return;
        if( distance < vv.size()){
            vv[distance].push_back(root->val);    
        }
        else{
            vector<int> n;
            n.push_back(root->val);
            vv.push_back(n);
        }
        
        
        dfs(root->left,distance+1);
        dfs(root->right, distance+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        dfs(root,0);
        return vv;
        // if(root == NULL)return vector<vector<int>>();
        
    }
};