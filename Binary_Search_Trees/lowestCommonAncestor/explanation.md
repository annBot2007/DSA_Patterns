## LeetCode Problem 235

We're given three things: the root of a binary search tree, and two nodes, p and q
We're supposed to find a common ancestor of the two nodes which has the lowest value (so not automatically the root, unless, of course, that is actually the LCA)

The logic behind it stems from the most important and defining characteristic of binary search trees: the fact that the left subtree has values lower than the root,
and the right subtree always has values higher than the root.

Using that fact, we logically know that:
1. if the root is larger than both the target nodes, then that means we have to keep searching in the left subtree
2. if the root is smaller than both the target nodes, then we have to keeping searching in the right subtree
3. else, the root is the lowest common ancestor (it is in between p and q in terms of magnitude)

The the base case : if the root is NULL, then we return NULL (if the BST is empty, or if we've reached the end, then we return NULL)

### Complexity:
#### Time Complexity:
1. O(H) where H is the height of the BST
2. Worst case: O(N) where N is the number of nodes in the BST, in a skewed BST (very bad)
3. Best case: O(log N) where N is the number of nodes in the BST, in a balance BST (very good)

#### Space Complexity:
O(H) where H is the height of the BST
