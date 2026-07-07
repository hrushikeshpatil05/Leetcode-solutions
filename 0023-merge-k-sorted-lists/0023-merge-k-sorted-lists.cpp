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
struct customCompare {
    bool operator()(const ListNode* a, const ListNode* b) {
        // For a Min-Heap, we want the node with the LARGER value to have LOWER priority,
        // so it sinks to the bottom. Thus, we use '>' instead of '<'.
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,customCompare>pq;

        for(auto x:lists) {
            if (x != nullptr) {
                pq.push(x);
            }
        }
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if(!top) {
                continue;
            }
            if(top && top->next) {
                pq.push(top->next);
            }
            top->next = nullptr;
            curr->next = top;
            curr = curr->next;
        }
        return ans->next;
    }
};