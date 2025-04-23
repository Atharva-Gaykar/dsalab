#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *buildTree(TreeNode *currentNode)
{
    if (currentNode == NULL)
        return NULL;

    int leftData, rightData;

    
    printf("Enter left child of %d (-1 for NULL): ", currentNode->data);
    scanf("%d", &leftData);
    if (leftData != -1)
    {
        currentNode->left = buildTree(createNode(leftData));
    }
    else
    {
        currentNode->left = NULL;
    }

    // Input for right child
    printf("Enter right child of %d (-1 for NULL): ", currentNode->data);
    scanf("%d", &rightData);
    if (rightData != -1)
    {
        currentNode->right = buildTree(createNode(rightData));
    }
    else
    {
        currentNode->right = NULL;
    }

    return currentNode;
}

int countleaf_nodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int l = countleaf_nodes(root->left);
    int r = countleaf_nodes(root->right);

    return l + r;
}

// Function to print the tree in in-order traversal
void printTree_inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    printTree_inorder(root->left);
    printf("%d ", root->data);
    printTree_inorder(root->right);
}

void printTree_postorder(TreeNode *root)
{
    if (root == NULL)
        return;

    printTree_postorder(root->left);
    printTree_postorder(root->right);
    printf("%d ", root->data);
}

void printTree_preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);

    printTree_postorder(root->left);
    printTree_postorder(root->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int calculate_height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = calculate_height(root->left);
    int r = calculate_height(root->right);

    return max(l, r) + 1;
}

// Function to delete the entire tree
void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

int main()
{
    int rootValue;
    printf("Enter root node value: ");
    scanf("%d", &rootValue);
    TreeNode *root = createNode(rootValue);

    root = buildTree(root);

    printf("\nTree elements (in-order): ");
    printTree_inorder(root);
    printf("\n");

    printf("\nTree elements (pre-order): ");
    printTree_preorder(root);
    printf("\n");

    printf("\nTree elements (post-order): ");
    printTree_postorder(root);
    printf("\n");

    printf("total leaf nodes are %d\n", countleaf_nodes(root));

    // Free allocated memory
    deleteTree(root);

    return 0;
}