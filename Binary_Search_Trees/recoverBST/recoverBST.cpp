class Solution {
public:
    // Pointers to track nodes across recursive calls
    TreeNode* prev = NULL;   // Keeps track of the previously visited node in in-order sequence
    TreeNode* first = NULL;  // Points to the first swapped node (out-of-order prev)
    TreeNode* second = NULL; // Points to the second swapped node (out-of-order root)

    void inorder(TreeNode* root){
        if(root == NULL) return; // Base case: end of branch

        // 1. Visit left subtree
        inorder(root -> left);

        // 2. Process current node
        // Check if current node violates the sorted BST property
        if(prev != NULL && prev -> val > root -> val){ 
            // First time detecting an inversion:
            if(first == NULL){
                first = prev; // The larger element (prev) is the first faulty node
            }
            // Always update second to current node (root) on any inversion
            second = root; 
        }

        // Update prev pointer to current node before moving right
        prev = root;

        // 3. Visit right subtree
        inorder(root -> right);
    }

    void recoverTree(TreeNode* root) {
        // Step 1: Traverse tree to identify the two swapped nodes
        inorder(root);

        // Step 2: Swap values of the two identified nodes to fix the BST
        int temp = first -> val;
        first -> val = second -> val;
        second -> val = temp;
    }
};
