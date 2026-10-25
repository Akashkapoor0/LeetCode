class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = nullptr;
        int carry = 0;

        while (temp1 && temp2) {
            int sum = temp1->val + temp2->val + carry;
            temp1->val = sum % 10;
            carry = sum / 10;

            prev = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp2) {
            int sum = temp2->val + carry;
            prev->next = new ListNode(sum % 10);
            carry = sum / 10;

            prev = prev->next;
            temp2 = temp2->next;
        }

        while (temp1) {
            int sum = temp1->val + carry;
            temp1->val = sum % 10;
            carry = sum / 10;

            prev = temp1;
            temp1 = temp1->next;
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return reverse(l1);
    }
};