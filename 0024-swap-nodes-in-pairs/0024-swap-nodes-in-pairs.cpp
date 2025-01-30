class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* t = swapPairs(head->next->next);
        ListNode* p = head->next;
        p->next = head;
        head->next = t;
        return p;
    }
};