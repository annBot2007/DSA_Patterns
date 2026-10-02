### Leetcode 99
#### Medium

Again, simple logic. Goes off the fact that Binary Search Trees inorder traversal is strictly in increasing order.

So the issue is that two elements have been swapped in this sorted list. We need to find those two elements and swap them back to make sure that they follow BST rules.

There are two cases:
i) Non-adjacent swap (two inversion points)
  e.g., Sorted: [1, 2, 3, 4, 5] and we're given [1, 5, 3, 4, 2]
  Essentially, 5 and 2 are swapped. There are two inversion points: (1, 5) and (4, 2)
  first inversion:
    first: 5 (prev)
    second: temporarily 3 (the root)
  second inversion:
    second: updated to 2

  swap first and second to get the original list back

ii) Adject swap (one inversion point)
  e.g., Sorted: [1, 2, 3, 4, 5] and we're given [1, 3, 2, 4, 5]
  only one inversion:
    first: 3 (prev)
    second: 2 (root)

  
