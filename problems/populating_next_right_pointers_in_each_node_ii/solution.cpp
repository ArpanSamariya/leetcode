/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    map<int,vector<Node*>> mp;
    Node* connect(Node* root) {
        helper(root,0);
        
        for(auto m : mp){
            for(int i = 0; i < m.second.size() - 1; i++){
                m.second[i]->next = m.second[i+1];
            }
        }
        return root;
    }
    
    void helper(Node* curr, int h){
        
        if(!curr) return;
        mp[h].push_back(curr);
        helper(curr->left, h+1);
        helper(curr->right, h+1);
    }
};