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
    vector<int> inorder;
    vector<int> postorder;
    map<int,int> mp;
    int post_idx;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        this->inorder = inorder;
        this->postorder = postorder;
        
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        post_idx = postorder.size() - 1;
        // TreeNode* root = helper(0, inorder.size() - 1);

         // TreeNode* tmp = &root;
        
        return helper(0, inorder.size() - 1);
    }
    
    TreeNode* helper(int left , int right) {
        if(left > right)
            return NULL;
        
        int currRootVal = postorder[post_idx];
        TreeNode* currRoot = new TreeNode(currRootVal);
        // currRoot.val = currRootVal;
        
        int index = mp[currRootVal];
        post_idx--;
        currRoot->right = helper(index + 1, right);
        currRoot->left = helper(left, index - 1);
        
        return currRoot;
    }
    
};