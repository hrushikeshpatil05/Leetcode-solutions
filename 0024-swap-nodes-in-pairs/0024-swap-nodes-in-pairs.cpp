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

    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* curr = new ListNode(0);
        curr->next = head;
        ListNode* prev = curr;

        while(prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            ListNode* next = second->next;

            first->next = next;
            second->next = first;
            prev->next = second;

            prev = first;
        }
        return curr->next;
    }
};