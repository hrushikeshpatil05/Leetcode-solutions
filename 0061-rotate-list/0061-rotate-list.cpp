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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int length = 0;

        ListNode* dummy = head;

        while(dummy) {
            length++;
            dummy = dummy->next;
        }

        k = k%length;

        if(k == 0) {
            return head;
        }

        int reqNodes = length - k - 1;

        ListNode* curr = head;

        while(reqNodes--) {
            curr = curr->next;
        }

        ListNode* firstNode = curr->next;

        ListNode* lastNode = firstNode;

        while(lastNode->next) {
            lastNode = lastNode->next;
        }

        curr->next = nullptr;

        lastNode->next = head;

        return firstNode;
    }
};