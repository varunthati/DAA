class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while (pre != nullptr) {
            ListNode* cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur->next;
                if (cur == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* node = pre->next;
            ListNode* nxt = cur->next;
            cur->next = nullptr;
            pre->next = reverse(node);
            node->next = nxt;
            pre = node;
        }
        return dummy->next;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = nxt;
        }
        return dummy->next;
    }
};