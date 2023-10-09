// You are using GCC
#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node* left;
    struct node* right;
    
};

// Inorder traversal 
void inorderTraversal(struct node* root){
    if(root == NULL)
    return ;
    inorderTraversal(root->left);
    printf("%d  ",root->item);
    inorderTraversal(root->right);
}

//preorderTraversal traversal 
void preorderTraversal(struct node* root){
    if(root == NULL) 
    return ;
    printf("%d  ",root->item);          //root
    preorderTraversal(root->left);       //left  
    preorderTraversal(root->right);      //right        
}

// postorderTraversal traversal 
void postorderTraversal(struct node* root){
    if(root == NULL )
    return ;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d  ",root->item);
}

// Create a new node
struct node* createNode(int value){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

//Insert on the lft of the node 
struct node* insertLeft(struct node* root, int value){
    root->left = createNode(value);
    return root->left;
}

//Insert on the right of the node
struct node* insertRight(struct node* root, int value){
    root->right = createNode(value);
    return root->right;
    
}

int main(){
    struct node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    
    insertLeft(root->left->left, 7);
    
    insertRight(root->left->left->left, 9);
    
    insertRight(root->right,6);
    insertRight(root->right->right, 8);
    
    printf("Inorder traversal:\n");
    inorderTraversal(root);
    printf("\n");
    printf("\nPreorder traversal:\n");
    preorderTraversal(root);
    printf("\n");
    printf("\nPostorder traversal:\n");
    postorderTraversal(root);
    
    return 0;
}
