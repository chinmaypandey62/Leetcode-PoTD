# LeetCode Problem: Merge Nodes in Between Zeros

## Problem Statement

[LeetCode Problem Link](https://leetcode.com/problems/merge-nodes-in-between-zeros/)

You are given the head of a linked list, which contains a series of integers separated by zeroes. The task is to merge the nodes in between the zeroes into a single node with their sum and return the modified list.

## Intuition

To solve this problem, we need to iterate through the linked list, summing the values of nodes until we encounter a zero. When a zero is encountered, we create a new node with the accumulated sum and continue the process.

## Approach

1. **Skip Initial Zero**: Start from the node after the initial zero.
2. **Accumulate Values**: Traverse the linked list, accumulating the values of nodes until a zero is encountered.
3. **Create New Nodes**: When a zero is encountered, create a new node with the accumulated sum and reset the sum.
4. **Update Pointers**: Update pointers to build the new linked list.
5. **Return New List**: Return the head of the newly created list.

## Code

```cpp
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
```

## Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of nodes in the linked list. We traverse the list once.
- **Space Complexity**: O(1), not counting the space for the output list. We only use a few pointers and integer variables.

## How to Contribute

1. Fork the repository.
2. Create a new branch.
3. Add your solution.
4. Create a pull request.