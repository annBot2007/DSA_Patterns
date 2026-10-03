class Solution {
public:
    Node* connect(Node* root) {
        // Base case: If the tree is empty or has no children, return root as-is
        if(root == NULL || root -> left == NULL){
            return root;
        }

        // Initialize a queue for Level-Order Traversal (BFS)
        queue<Node*> q;

        // Push the root node to start processing Level 0
        q.push(root);

        // Push NULL as a delimiter marking the end of Level 0
        q.push(NULL); 
        
        // Track the previously processed node on the same level
        Node* prev = NULL;

        // Loop until the queue is empty
        while(q.size() > 0){
            // Fetch and remove the front node from the queue
            Node* curr = q.front();
            q.pop();

            // Case 1: We hit a level boundary marker (curr is NULL)
            if(curr == NULL){
                // If queue is empty, all levels are processed — break the loop
                if(q.size() == 0){
                    break;
                }

                // Push NULL to mark the end of the next level we just finished enqueuing
                q.push(NULL);
            } 
            // Case 2: Standard node processing
            else { 
                // Push left child to queue if present
                if(curr -> left != NULL){
                    q.push(curr -> left);
                }

                // Push right child to queue if present
                if(curr -> right != NULL){
                    q.push(curr -> right);
                }

                // If a previous node exists on this level, connect it to the current node
                if(prev != NULL){
                    prev -> next = curr;
                }
            }

            // Update prev pointer to current node for the next iteration
            prev = curr;
        }

        // Return the modified root node with all `next` pointers populated
        return root;
    }
};
