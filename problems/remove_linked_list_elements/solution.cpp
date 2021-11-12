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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;

      if (toDelete != nullptr) {
        delete toDelete;
        toDelete = nullptr;
      }
    }

    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};

/*

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
     
        ListNode* tmp = head;
        ListNode sentinel = ListNode(-1,head);
        ListNode* curr = &sentinel;

        
        while(curr and curr->next != NULL){
            if(curr->next != NULL and curr->next->val == val){
                curr->next = curr->next->next;
            }
            else
             curr = curr->next;
        }
        
        return sentinel.next;
    }
};

*/

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* curr = head;
//         ListNode* tmp = head;
      
//         while(head!= NULL && head->val == val){
//             tmp = head->next;
//             head->next = NULL;
//             head = tmp;
//         }
        
//         curr = head;
        
//         while(curr and curr->next != NULL){
//             if(curr->next != NULL and curr->next->val == val){
//                 curr->next = curr->next->next;
//             }
//             else
//              curr = curr->next;
//         }
        
//         return head;
//     }
// };