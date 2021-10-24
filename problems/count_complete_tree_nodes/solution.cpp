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
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int height = 1;
        TreeNode* tmp = root;
        
        while(tmp->left){
            tmp = tmp->left;
            height++;
        }
        
        int ans = (1 << height) -1;
        
    
     function < void (TreeNode* , int) > dfs = [&]( TreeNode* curr, int h) {
            if ( !curr and h == height ) {
                ans = ans - 1;
                return;
            }
         
         if(!curr) return;
            
            dfs(curr->right, h + 1);
            dfs(curr->left, h + 1);
        };
    
        dfs(root,1);
        
        return ans;
    }
};