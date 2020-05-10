//
// Created by budopest on 5/10/20.
//

#ifndef BINARYTREE_BINARTTREE_H
#define BINARYTREE_BINARTTREE_H


/*
 * Define a type for the data that will be used
 * */
typedef struct{
    int num;
}NodeData;
/*
 * Define the tree node with
 * 1- Node data 2- ptr to the left node 3- ptr to the right node
 * */
typedef struct TreeNode{
    NodeData data;
    struct TreeNode *left,*right;
}TreeNode,*TreeNodePtr;
/*
* Define the pinary tree as a pointer to the root node
* */
typedef struct{
    TreeNodePtr root;
}BinaryTree;

#endif //BINARYTREE_BINARTTREE_H
