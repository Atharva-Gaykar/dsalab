#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int idx = -1;

int countNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct TreeNode *root, int *A)
{
    if (root == NULL)
        return;
    inorder(root->left, A);
    idx++;
    A[idx] = root->data;
    inorder(root->right, A);
}

void find_smallest(struct TreeNode *root, int *A, int K)
{
    int N = countNodes(root);
    printf("the Kth smallest number is %d\n", A[K - 1]);
}

void function_k(struct TreeNode *root, int *K)
{
    if (root == NULL)
    {
        return;
    }

    function_k(root->left, K);
    (*K)--;
    if (*K == 0)
    {
        printf("%d ", root->data);
        return;
    }
    function_k(root->right, K);
}

void printTree(struct TreeNode *root)
{
    if (root == NULL)
        return;

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main()
{
    struct TreeNode *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    printf("Inorder traversal: ");
    printTree(root);
    printf("\n");

    int N = countNodes(root);
    int A[N];
    idx = -1;
    inorder(root, A);

    int K ;
    scanf("%d", &K);
    printf("The %dth smallest element is: ", K);
    int tempK = K;
    function_k(root, &tempK);
    printf("\n");

    return 0;
}