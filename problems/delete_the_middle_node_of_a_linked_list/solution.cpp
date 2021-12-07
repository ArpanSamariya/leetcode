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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* mid = head;
        
        
        
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            mid = slow;
            slow = slow->next;
        }
        if(fast == head){
            delete(head);
            return NULL;
        }
        ListNode* tmp = slow;
        mid ->next = slow->next;
        delete(tmp);
        return head;
    }
};