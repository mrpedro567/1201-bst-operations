#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    Node* rChild;
    Node* lChild; 
}Node;

void insertNode(Node** root, int value){
    Node* insert = (Node*)calloc(1, sizeof(Node));
    Node* current = *root;
    Node* tmp = *root;

    insert->data = value;
    insert->lChild = NULL;
    insert->rChild = NULL;
    
    if(*root == NULL){
        *root = insert;
    } 
    else{
        while(tmp != NULL){
            current = tmp;
            if(current->data > value){
                tmp = current->lChild;
            }
            else{
                tmp = current->rChild;
            }
        }

        if(value < current->data){
            current->lChild = insert;
        }
        else{
            current->rChild = insert;
        }
    }
}

void preOrder(Node* root){
    Node* current = root;

    if(current == NULL){
        return;
    }

    printf("%d ", current->data);

    preOrder(current->lChild);

    preOrder(current->rChild);
}

void inOrder(Node* root){
    Node* current = root;

    if(current == NULL){
        return;
    }

    inOrder(current->lChild);

    printf("%d ", current->data);

    inOrder(current->rChild);
}

void postOrder(Node* root){
    Node* current = root;

    if(current == NULL){
        return;
    }

    postOrder(current->lChild);
    postOrder(current->rChild);
    printf("%d ", current->data);
}

void freeTree(Node** root){
    Node* current = *root;

    if(current == NULL){
        return;
    }
     
    freeTree(&current->lChild);
    freeTree(&current->rChild);
    free(current);
}

int main(){

    return 0;
}