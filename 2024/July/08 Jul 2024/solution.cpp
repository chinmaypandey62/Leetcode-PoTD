struct Node {
    int val;
    Node* next;
};

#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findTheWinner(int n, int k) {
        Node* prev = nullptr;
        Node* head = insertNodes(n, prev);
        Node* curr = head;
        int i = 0;

        while (curr != curr->next) {
            ++i;
            if (i == k) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                i = 0;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return curr->val;
    }

private:
    Node* insertNodes(int& n, Node*& prev) {
        Node* head = new Node(1);
        Node* curr = head;
        int i = 2;

        while(i <= n) {
            curr->next = new Node(i++);
            curr = curr->next;
        }

        curr->next = head;
        prev = curr;
        return head;
    }
};