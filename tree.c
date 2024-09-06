#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node* createnode(int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

struct node* insertdata(int data, struct node *root) {
    if (root == NULL)
        return createnode(data);
    else if (data < root->data)
        root->left = insertdata(data, root->left);
    else if (data > root->data)
        root->right = insertdata(data, root->right);
    return root;
}

void preorder(struct node *root) {
    if (root == NULL)
        return;
	printf("%d ", root->data);
    preorder(root->left);  
    preorder(root->right);
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);  
    inorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);  
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    root = insertdata(40, root);
    root = insertdata(25, root);
    root = insertdata(56, root);
    root = insertdata(17, root);
    root = insertdata(86, root);
    root = insertdata(69, root);
    root = insertdata(29, root);
    root = insertdata(99, root);
    
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}