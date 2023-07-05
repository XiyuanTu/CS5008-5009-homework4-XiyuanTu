#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the binary search tree
struct TreeNode* insert(struct TreeNode* node, int val) {
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(val);
    
    // Otherwise, recur down the tree
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    
    // Return the (unchanged) node pointer
    return node;
}

// Function to find the value in the BST that is closest to the target
int closestValue(struct TreeNode* root, double target) {
    int closest = root->val;
    double diff = fabs((double)root->val - target);
    
    struct TreeNode* curr = root;
    while (curr != NULL) {
        double currDiff = fabs((double)curr->val - target);
        if (currDiff < diff) {
            closest = curr->val;
            diff = currDiff;
        }
        
        if (target < curr->val)
            curr = curr->left;
        else if (target > curr->val)
            curr = curr->right;
        else
            break;
    }
    
    return closest;
}

// Function to free the allocated memory of the binary tree
void freeTree(struct TreeNode* node) {
    if (node == NULL)
        return;
    
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    // Create the binary search tree based on user input
    struct TreeNode* root = NULL;
    int n;
    printf("Enter the number of elements in the binary search tree: ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    // Get the target value from the user
    double target;
    printf("Enter the target value: ");
    scanf("%lf", &target);
    
    // Find the value in the BST that is closest to the target
    int closest = closestValue(root, target);
    
    // Print the result
    printf("Closest number = %d\n", closest);
    
    // Free the allocated memory
    freeTree(root);
    
    return 0;
}
