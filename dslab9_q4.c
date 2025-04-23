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

int idx = -1;
TreeNode *buildTree(int preorder[], int size)
{
    idx++;
    if (idx >= size || preorder[idx] == -1)
    {
        return NULL;
    }

    TreeNode *node = createNode(preorder[idx]);

    node->left = buildTree(preorder, size);
    node->right = buildTree(preorder, size);

    return node;
}

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

void pre_order_transversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    pre_order_transversal(root->left);
    pre_order_transversal(root->right);
}

void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int node_count = 0;
void countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    node_count++;
    countNodes(root->left);
    countNodes(root->right);
}

int idx2 = -1;
void build_vector(int nums[], TreeNode *root, int size)
{
    idx2++;
    if (idx2 >= size)
        return;

    if (root == NULL)
    {
        nums[idx2] = -1;
        return;
    }

    nums[idx2] = root->data;
    build_vector(nums, root->left, size);
    build_vector(nums, root->right, size);
}

int count_node(TreeNode *root)
{
    if (root == NULL){
        return 0;
    }
    int l = count_node(root->left);
    int r = count_node(root->right);
    return 1 + l + r;
}

int main()
{
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    idx = -1; 
    TreeNode *root = buildTree(preorder, size);

  
    node_count = 0;
    countNodes(root);
    printf("Number of nodes: %d\n", node_count);

    int nums[2 * node_count]; 

    idx2 = -1; 
    build_vector(nums, root, 2 * node_count);

    printf("The array is: ");
    for (int i = 0; i < 2 * node_count; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("Tree elements (pre-order): ");
    pre_order_transversal(root);
    printf("\n");

    printf("Tree elements (in-order): ");
    printTree(root);
    printf("\n");

    printf("Total nodes counted recursively: %d\n", count_node(root));

    deleteTree(root);

    return 0;
}