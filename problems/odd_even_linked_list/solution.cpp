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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        if(head->next->next == NULL) return head;
        
        ListNode* odd = head;
        ListNode* oddStart = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;
        
       while(even != NULL and even->next != NULL ){
           odd->next = even->next;
           odd = odd->next;
           // if(even->next->next == NULL){
           //     even->next = NULL;
           // } else {
           //     even->next = odd->next;
           //     even = even->next;
           // }
               even->next = odd->next;
               even = even->next;
       }
        odd->next = evenStart;
        return oddStart;
    }
};