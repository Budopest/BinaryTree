
#include "BinartTree.h"

TreeNodePtr buildTree(int*, int);
void visit(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
void inOrder(TreeNodePtr);
TreeNodePtr buildBinarySearchTree(BinaryTree);
TreeNodePtr findORinsert(BinaryTree tree, NodeData data);

TreeNodePtr newTreeNode(NodeData data);

int main() {

    /*
     * build a tree with the numbers in array
     * 0 is null
     *
    */
    /*
     * old way to build the tree
    int numbers[21] ={5,4,3,0,2,0,0,10,0,0,7,8,0,0,12,21,0,0,11,0,0};
    TreeNodePtr p = buildTree(numbers,0);
     */
    BinaryTree stringTree;
    TreeNodePtr p;
    stringTree.root = NULL;
    NodeData data;
    p = buildBinarySearchTree(stringTree);
    /*
     * Test using find or insert function
    strcpy(data.word,"oop");
    stringTree.root = findORinsert(stringTree,data);
    strcpy(data.word,"nO");
    p = findORinsert(stringTree,data);
    strcpy(data.word,"alola");
    p = findORinsert(stringTree,data);
    */


    printf("\nPreorder traversal :\n");
    preOrder(stringTree.root);
    printf("\npostorder traversal :\n");
    postOrder(stringTree.root);
    printf("\nPinorder traversal :\n");
    inOrder(stringTree.root);

}

TreeNodePtr buildBinarySearchTree(BinaryTree binaryTree) {
    /*
     * Read input from the console
     * return pointer to the added node
     * */

    char * inputString[MAX_SIZE+1];
    TreeNodePtr p = NULL;
    printf("Enter a string to add or 0 \"zero\" to end: \n");

    while (strcmp(scanf("%s", inputString), "0") != 0){
        //printf("%s\n",inputString);
        NodeData data;
        strcpy(data.word,inputString);
        if(binaryTree.root = NULL)
            binaryTree.root = findORinsert(binaryTree,data);
        else
            p= findORinsert(binaryTree,data);
    }
    inOrder(binaryTree.root);
    return binaryTree.root;

}

TreeNodePtr findORinsert(BinaryTree tree, NodeData data) {
    /*
     * search and return pointer to the found node
     * if not found insert and return pointer to the new added node
     * */

    if(tree.root == NULL) return newTreeNode(data);
    TreeNodePtr current = tree.root;
    int cmp;
    while ((cmp= strcmp(data.word,current->data.word))!= 0){
        if(cmp<0){ // try left
            if(current->left == NULL) return current->left = newTreeNode(data);
            current = current->left;
        } else{ // try right
            if(current->right == NULL) return current->right = newTreeNode(data);
            current = current->right;
        }
    }
    // d is in the tree return pointer to the existing node
    return current;
}

TreeNodePtr newTreeNode(NodeData data) {
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    if(p == NULL) {
        printf("Error allocating memory");
        return NULL;
    }
    p->data = data;
    p->right=NULL;
    p->left=NULL;
}

void visit(TreeNodePtr p){
    /*print the number stored in the node p*/
    printf("%s ",p->data.word);
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

/*
TreeNodePtr buildTree(int* numbers,int index){
    if(*(numbers+index) == 0)
        return NULL;
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    p->data.word = *(numbers+index);
    index++;
    p->left = buildTree(numbers,index);
    p->right = buildTree(numbers,index);
    return p;
}
 */