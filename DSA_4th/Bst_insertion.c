#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// Structure for BST node
struct Node
 {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a node in BST
struct Node* insertNode(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
   if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
// Function to perform inorder traversal and store in a file
void inorderTraversal(struct Node* root, FILE* file)
 {
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, file);
    fprintf(file, "%d ", root->data);
    inorderTraversal(root->right, file);
}
// Function to perform postorder traversal and store in a file
void postorderTraversal(struct Node* root, FILE* file)
 {
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left, file);
    postorderTraversal(root->right, file);
    fprintf(file, "%d ", root->data);
}
// Function to perform Pre-order traversal and store in a file
void preorderTraversal(struct Node* root, FILE* file)
 {
    if (root == NULL)
    {
        return;
    }

    fprintf(file, "%d ", root->data);
    preorderTraversal(root->left, file);
    preorderTraversal(root->right, file);
}
int main()
{
    int i, num;
    struct Node* root = NULL;
   // Generate random numbers and insert them into the BST
    FILE* inputFile = fopen("input.txt", "w");
    int l=10,u=50;
    for (i = 0; i < 10; i++)
    {
        num = (rand()%(u-l+1))+1;  // Generating random numbers between 10 and 50
        fprintf(inputFile, "%d ", num);
        root = insertNode(root, num);
    }
    fclose(inputFile);
    // Perform inorder traversal and store in a file
    FILE* inorderFile = fopen("in.txt", "w");
    inorderTraversal(root, inorderFile);
    fclose(inorderFile);

    // Perform postorder traversal and store in a file
    FILE* postorderFile = fopen("post.txt", "w");
    postorderTraversal(root, postorderFile);
    fclose(postorderFile);

    // Perform preorder traversal and store in a file
    FILE* preorderFile = fopen("pre.txt", "w");
    preorderTraversal(root, preorderFile);
    fclose(preorderFile);
  return 0;
}
