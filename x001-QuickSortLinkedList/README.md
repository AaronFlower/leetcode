## 206. Reverse Linked List 

### Description

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

### Analysis
#### 1. Simple with a stack

First, to push every element to a stack. Then you pop the stack to replace the list value sequencely. 
In this method we need o(2n) and O(n) space.

#### 2. Recursion.
Since, we can use a stack to stack up a list elements. We can use a recursion to elimate the O(n) space.
Our recursion terminate when the node is the last node, and continue otherwise. When exit function stack call we need to 
reassign node->next pointer.

**Note**: In fact, function call stack process which will cost more memory.

### 3. Create a new list.
We can create a new list. when we insert a note into the new list we keep the new node is unshifted in the head. 
We just need to iterate the old list to get every node and unshift the node to the new list.
