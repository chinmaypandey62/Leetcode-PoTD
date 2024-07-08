# LeetCode Problem: Find the Winner of the Circular Game

## Problem Statement

[LeetCode Problem Link](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

There are `n` friends sitting in a circle, numbered from `1` to `n`. They play a game by removing the `k`-th person in the circle until only one person remains. The task is to find the winner of this game.

## Intuition

The problem is a variation of the Josephus problem. We can solve it by simulating the process of eliminating every `k`-th person until only one person remains.

## Approach

1. **Create a Circular Linked List**: Initialize a circular linked list with `n` nodes where each node represents a person.
2. **Simulate the Game**: Traverse the circular linked list and remove every `k`-th node until only one node remains.
3. **Return the Winner**: The remaining node will be the winner.

## Code

```cpp
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
```

## Complexity Analysis

- **Time Complexity**: O(n * k), where `n` is the number of nodes and `k` is the step count. In the worst case, every node is visited `k` times.
- **Space Complexity**: O(n), where `n` is the number of nodes in the circular linked list.

## How to Contribute

1. Fork the repository.
2. Create a new branch.
3. Add your solution.
4. Create a pull request.