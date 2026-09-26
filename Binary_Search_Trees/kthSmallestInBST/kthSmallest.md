## Leetcode Problem 230
We're given the root of Binary Search Tree and an integer k. We're supposed to find the kth smallest element in the BST.

### Difficulty: Medium

### Logic
Very simple logic. When you do the inorder traversal of a BST (left, root, right), it is always in ascending order.
We just have to do the inorder traversal and keep a counter, then return value of the counter when the counter's value is equal to k

#### Time Complexity: 
