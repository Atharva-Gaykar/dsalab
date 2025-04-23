#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* FindMin(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

struct Node* Delete(struct Node *root, int data) {
    if(root == NULL) return root; 
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) { 
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if(root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else { 
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(Node *root) {
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

Node* Insert(Node *root, int data) {
    if(root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else 
        root->right = Insert(root->right, data);
    return root;
}


Node* Search(Node* root, int data) {
    if(root == NULL || root->data == data)
        return root;
    if(data < root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int main() {
    Node* root = NULL;
    root = Insert(root, 5); 
    root = Insert(root, 10);
    root = Insert(root, 3); 
    root = Insert(root, 4); 
    root = Insert(root, 1); 
    root = Insert(root, 11);

    printf("Inorder before deletion: ");
    Inorder(root);
    printf("\n");

    // Search for a value
    int searchValue = 10;
    Node* found = Search(root, searchValue);
    if(found != NULL)
        printf("%d found in the tree\n", searchValue);
    else
        printf("%d not found in the tree\n", searchValue);

    root = Delete(root, 5);

    printf("Inorder after deletion: ");
    Inorder(root);
    printf("\n");

    
    
    return 0;
}