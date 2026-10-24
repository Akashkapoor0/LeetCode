class Solution {
public:
    void bfs(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* dummy = new Node(0);
            Node* temp = dummy;
            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                temp->next = curr;
                temp = temp->next;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            temp->next = nullptr;
            delete dummy;
        }
    }

    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};
