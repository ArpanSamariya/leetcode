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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int cnt = 1;
        ListNode *trail, *prev = NULL, *root = head;
        while(head){
            
            if(cnt > n){
                prev = trail;
                trail = trail->next;
            }
            if(cnt == n){
                trail = root;
                prev = trail;
            } 
            head = head -> next;
            cnt++;
        }
        if( prev == trail) return root->next;
        
        prev->next = trail->next;
        delete(trail);
        return root;    
    }
};