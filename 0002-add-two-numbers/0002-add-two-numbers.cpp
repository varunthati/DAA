class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            // get values if linked list is not null
            // otherwise the value is 0
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            // add values
            int value = v1 + v2 + carry;
            // update carry value
            // only can be 0 or 1
            carry = floor(value / 10);
            // value can be two digits number
            // we only want one digit number
            value %= 10;
            // insert it into new linked list
            curr->next = new ListNode(value);
            // update pointers
            curr = curr->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy->next;
    }
};