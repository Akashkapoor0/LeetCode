/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* temp = head;
        Node* nxt = head->next;
        while (temp) {
            temp->next = new Node(temp->val);
            temp = temp->next;
            temp->next = nxt;
            temp = temp->next;
            if (nxt)
                nxt = nxt->next;
        }
        temp = head;
        while (temp) {
            if (!temp->next)
                break;

            if (temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }
        Node* head1 = head->next;
        temp = head;
        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            temp = temp->next;
        }
        return head1;
    }
};