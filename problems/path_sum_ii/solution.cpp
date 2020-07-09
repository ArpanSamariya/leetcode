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
    
    void fun(TreeNode* root, int target, vector<int> v, vector<vector<int>> *ans){
        if(root == NULL)return ;
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            int sum = 0 ;
            for(int i = 0 ; i < v.size(); i++) sum+=v[i];
            if(sum == target)
            {
                ans->push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        //  for(int i = 0 ; i < v.size(); i++) cout<<v[i]<<" ";
        // cout<<endl;
        fun(root->left, target, v, ans);
        fun(root->right, target, v, ans);
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> v;
        fun(root,sum,v,&ret);
        return ret;
    }
};