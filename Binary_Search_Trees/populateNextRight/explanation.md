# Leetcode 116: Populating Next Right Pointers in Each Node

## The Goal:
Connect all nodes at the same depth level from left to right using their next pointers

## Core Concept: Level Order Traversal
Breadth First Search with a queue and a delimiter marker (NULL) to process the tree level by level.
We connect each node to the node that is to its right, and if there is no node to its right, then we connected it to NULL

## The Algorithm
1. **Queue Traversal:** Nodes are processed in the order they appear level by level, left to right (level order traversal, or breadth first search)
2. **NULL Delimiter:**
   a. A NULL pointer pushed into the queue acts as a level boundary
   b. when curr == NULL is popped, it signifies that the current level is complete
   c. If the queue still has nodes, another NULL is pushed to mark the end of the next level
   d. prev is updated to NULL across all level boundaries so that the last node of a level doesn't point to the first node
3. **Connecting Nodes:** as nodes on a level are processed, prev -> next = curr connected consecutive nodes side-by-side

## Complexity:
Time Complexity: O(N)
Space Complexity: O(N)
