#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return 1 + getMax(leftHeight, rightHeight);
    }
}

void countNodesInLevel(struct Node* root, int level, int* count) {
    if (root == NULL)
        return;
    if (level == 1)
        (*count)++;
    else if (level > 1) {
        countNodesInLevel(root->left, level - 1, count);
        countNodesInLevel(root->right, level - 1, count);
    }
}

void countNodesPerLevel(struct Node* root) {
    int height = getHeight(root);
    int level;
    for (level = 1; level <= height; level++) {
        int count = 0;
        countNodesInLevel(root, level, &count);
        printf("Level %d: %d nodes\n", level, count);
    }
}
void inorder(struct Node* root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}
void displayTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }
    int i;
    // Increase distance between levels
    space +=3;
    // Process right child first
    displayTree(root->right, space);
    // Print current node after space
    printf("\n");
    for (i =3; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->value);

    // Process left child
    displayTree(root->left, space);
}
struct Node* insertNode(struct Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
   if (value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value >= root->value)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}
int main()
{
    struct Node* root = NULL;
    int value,i,num;
    char choice;
    int l=10,u=30;
    for (i = 0; i < 5; i++)
    {
        num = (rand()%(u-l+1))+1;  // Generating random numbers between 10 and 50
        printf( "%d\n", num);
        root = insertNode(root, num);
    }
    countNodesPerLevel(root);
    printf("\nInorder traversal of the binary tree: ");

    inorder(root);
     printf("\nBinary Tree ):\n");
    displayTree(root, 0);

    return 0;
}
