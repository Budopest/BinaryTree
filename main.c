#include <stdio.h>
#include <stdlib.h>
#include "BinartTree.h"

int main() {

    TreeNodePtr buildTree(int*, int);
    void visit(TreeNodePtr);

    /*
     * build a tree with the numbers in array
    */
    int numbers[10] ={5,4,3,2,10,7,8,12,21,11};
    buildTree(numbers,0);






}
TreeNodePtr buildTree(int* numbers,int index){
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