## 543. Diameter of Binary Tree

二叉树的直径，也就是二叉两个节点之间的最长路径，可能经过根结点，也可能不经过根结点。

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

```
          1
         / \
        2   3
       / \
      4   5
```

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.


## Analysis

像这种可能经过根结点，也可能不经过的，在写递归的时候需要单独考虑左右子树的值是否是最优。

### References

1. [Diameter of Binary Tree](https://www.geeksforgeeks.org/diameter-of-a-binary-tree/)
