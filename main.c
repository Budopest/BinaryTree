#include <stdio.h>
#include <stdlib.h>
#include "BinartTree.h"

TreeNodePtr buildTree(int*, int);
void visit(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
void inOrder(TreeNodePtr);

int main() {

    /*
     * build a tree with the numbers in array
     * 0 is null
     *
    */
    int numbers[21] ={5,4,3,0,2,0,0,10,0,0,7,8,0,0,12,21,0,0,11,0,0};
    TreeNodePtr p = buildTree(numbers,0);
    printf("\nPreorder traversal :\n");
    preOrder(p);
    printf("\npostorder traversal :\n");
    postOrder(p);
    printf("\nPinorder traversal :\n");
    inOrder(p);

}
TreeNodePtr buildTree(int* numbers,int index){
    if(*(numbers+index) == 0)
        return NULL;
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    p->data.num = *(numbers+index);
    p->left = buildTree(numbers,++index);
    p->right = buildTree(numbers,++index);
    return p;
}
void visit(TreeNodePtr p){
    /*print the number stored in the node p*/
    printf("%d ",p->data.num);
}
void preOrder(TreeNodePtr p){
    if(p != NULL){
        visit(p);
        preOrder(p->left);
        preOrder(p->right);
    }

}
void postOrder(TreeNodePtr p){
    if(p != NULL){
        postOrder(p->left);
        postOrder(p->right);
        visit(p);
    }
}
void inOrder(TreeNodePtr p){
    if(p != NULL){
        inOrder(p->left);
        visit(p);
        inOrder(p->right);
    }
}