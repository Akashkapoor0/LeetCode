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
    ListNode* middleLL(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge2LL(ListNode*left,ListNode*right){
      ListNode*dummy=new ListNode(-100);
      ListNode*temp=dummy;
      while(left!=nullptr && right!=nullptr){
        if(left->val < right->val){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        else{
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
      }
      if(left!=nullptr){
        temp->next=left;
      }
      else{
        temp->next=right;
      }
      temp=dummy->next;
      delete dummy;
      return temp;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*middle=middleLL(head);
        ListNode*left=head;
        ListNode*right=middle->next;
        middle->next=nullptr;
        left=sortList(left);
        right=sortList(right);
        return merge2LL(left,right);
    }
};