class Solution {
public:
    void traverse(Node* root) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                if (prev != nullptr) {
                    prev->next = curr;
                }
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
    }

    Node* connect(Node* root) {
        traverse(root);
        return root;
    }
};