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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        ListNode* unique = dummy;
        int count = 0;
        while (temp) {
            if(temp->next && temp->next->val == temp->val){
                count++;
            }
            else {
                if( count == 0){
                    unique->next = temp;
                    unique = unique->next;
                }
                count = 0;
            }
            temp = temp->next;
        }
        unique->next = nullptr;
        return dummy->next;
    }
};