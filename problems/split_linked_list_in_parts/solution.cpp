/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int cnt = 0;
        ListNode* root = head;
        ListNode* curr;
        vector<ListNode*> ret(k, NULL);
        
        if(head == NULL) return ret;
    
        while(head){
            cnt++;
            head = head->next;
        }
        
        int sz = cnt / k;
        int mod = cnt % k;
        cout<<cnt<<" "<<sz<<" "<<mod;
        curr = root;
        int index = 0;
        if(sz == 0){
            for(int i = 0 ; i < mod; i++){
                ret[index] = root;
                curr = root->next;
                root->next = NULL;
                root = curr;
                index++;
            }
//              for(int i = mod ; i < k; i++){
//                 ret[](NULL);
//             }
            
            return ret;
        }
        index = 0;
        while(root != NULL){
            int i = sz-1;
            // cout<<endl<<root->val;
            ret[index] = root;
            
            while(i != 0){
                root = root->next;
                i--;
            }
            if(mod){
                root = root->next;
                mod--;
            }
            curr = root->next;
            root->next = NULL;
            root = curr;
            index++;
        }
        return ret;
    }
};