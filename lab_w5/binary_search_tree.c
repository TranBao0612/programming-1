#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

/// @brief  function to create a node
struct Node * createNode(int data)
{
    struct Node * node = malloc(sizeof (struct Node));
    node->data = data;
    return node;
}

/* build the following tree
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
struct Node * buildCustomTree()
{
    struct Node * root = createNode(50);

    root->left = createNode(30);
    root->left->left = createNode(20);
    root->left->right = createNode(40);

    root->right = createNode(70);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    
    return root;
}

void freeMemory(struct Node * root)
{
    free(root);
}

// A utility function to do inorder traversal of BST
void inorder(struct Node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main()
{
    struct Node * root = buildCustomTree();
    inorder(root);

    freeMemory(root);
    return 0;
}