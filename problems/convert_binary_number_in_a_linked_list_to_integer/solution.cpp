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
    int getDecimalValue(ListNode* head) {
        
        string num = "";
            int ret = 0; 
            while(head){
                if(head->val == 1){
                    num += '1';
                } else
                    num += '0';
                head = head->next;
            }
        for(int i = 0 ; i < num.length(); i++){
            
            if(num[i] == '1'){
                ret += 1<<(num.length() - 1 -i);
            }
        }
        return ret;
    }
};