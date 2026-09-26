/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prevOrder = 0; // the counter, tells us how many nodes we've already visited
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return -1; // BASE CASE, indicate the the kth element hasn't been found 
        }

        int leftAns = kthSmallest(root -> left, k);
        if(leftAns != -1){
            return leftAns;
        }

        if(prevOrder + 1 == k){ // if the current node is the kth node that we're visiting,
            return root -> val; // then return its value
        }

        prevOrder = prevOrder + 1;
        
        int rightAns = kthSmallest(root -> right, k);
        if(rightAns != -1){
            return rightAns;
        }

        return -1;
    }
};
