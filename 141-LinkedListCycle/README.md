## 141. Linked List Cycle

### Description
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?


### Analysis

- Use two pointers, walker and runner.
- walker moves step by step. runner moves two steps at time.
- if the Linked List has a cycle walker and runner will meet at some
point.
