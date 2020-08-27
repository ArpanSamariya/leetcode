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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<pair<TreeNode*, int> > st;
        map<int,int> mp;
        st.push(make_pair(root,0));
        while(!st.empty()){
            // TreeNode *curr = st.top();
            pair<TreeNode*, int> p = st.top();
            st.pop();
            if((p.first)->left != NULL){
                st.push(make_pair((p.first)->left, p.second+1));    
            }
            if((p.first)->right != NULL){
                st.push(make_pair((p.first)->right, p.second+1));
            }
            if(mp.find(p.second) == mp.end()){
                mp.insert(make_pair(p.second, (p.first)->val));
            }
            
        }
        for(auto i = mp.begin(); i != mp.end(); i++){
            ans.push_back(i->second);
            // cout<<i->first<<" "<<i->second<<endl;
            
        }
        return ans;
    }
};