/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};

/*
class Solution {
public:
    void deleteNode(ListNode* node) {  
        ListNode* prev;
        while(node->next != NULL){
            prev = node;
            node->val = node->next->val;  
            node = node->next;
        }
        delete node;
        prev->next = NULL; 
    }
};
*/