class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;  // Skip the initial zero
        int sum = 0;
        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;

        while(head) {
            sum += head->val; 
            if(!head->val) {  // When zero is encountered
                curr->next = new ListNode(sum);
                sum = 0;
                curr = curr->next;
            }
            head = head->next;
        }

        return newHead->next;
    }
};