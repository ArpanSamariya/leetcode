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
    ListNode* middleNode(ListNode* head) {
        ListNode* root = head;
        
        while(head and head->next){
            head = head->next->next;
            root = root->next;
        }
//         int cnt = 0;
//         int mid = 0;
//         while(head){
//             cnt++;
//             head = head -> next;
//         }
        
//         mid = (cnt / 2) + 1;

//         for(int i = 1; i < mid; i++){
//             root = root->next;
//         }
        return root;
    }
};