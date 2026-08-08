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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr){
            //save next node
            ListNode* next = curr->next;
            //reverse node
            curr->next = prev;
            //move prev
            prev = curr;
            //move curr
            curr = next;
        }
        return prev;
    }
};
