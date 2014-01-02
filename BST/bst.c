#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

Node* traverse(Node *node,void *data,Compare compare){
    if(compare(data,node->data) == 0)
        return NULL;
    if(NULL == node->left && NULL == node->right)
        return node;
    if(compare(data,node->data) < 0)
        return traverse(node->left, data, compare);
    else return traverse(node->right, data, compare);
}

BST* createBST(Compare compare){
    BST* tree = calloc(1, sizeof(BST));
    tree->root = NULL;
    tree->compare = compare;
    return tree;
}
Node* createBSTNode(void *data){
    Node *node = calloc(1,sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
} 
int insertInBST(BST *tree, void *data){
    Node *node,*parentNode;
    if(NULL == tree->root){
        tree->root = createBSTNode(data);
        return 1;
    }
    parentNode = traverse(tree->root,data,tree->compare);
    if(parentNode){
        if(tree->compare(data,parentNode->data) > 0)
        parentNode->right = createBSTNode(data);
        else parentNode->left = createBSTNode(data);
    }
    else return 0;
    return 1;
}

int searchInBST(BST *tree, void *data){
    Node *parentNode,*rootNode;
    rootNode = tree->root;
    if(NULL == rootNode) return 0;
    if(NULL == traverse(rootNode, data, tree->compare))
    return 1;
    return 0;
}

Node* getParentNode(Node *node,void *data,Compare compare){
    if(node->right){
        if(compare(node->right->data,data) == 0) return node;
    }
    if(node->left){
        if(compare(node->left->data,data) == 0) return node;
    }
    if(compare(node->data,data) > 0)
            return getParentNode(node->left, data, compare);
    else return getParentNode(node->right, data, compare);
}

int deleteFromBST(BST* tree, void *data){
    Node* node = tree->root, *parentNode;
    if(0 == searchInBST(tree, data))    return 0;
    if(0 == tree->compare(node->data, data)){
        tree->root = NULL;
        return 1;
    }
    parentNode = getParentNode(node, data, tree->compare);
    if(parentNode->left){
        if(tree->compare((parentNode->left)->data,data) == 0){
            if(parentNode->left->right == NULL)
                parentNode->left = parentNode->left->left;
            else if(parentNode->left->left == NULL)
                parentNode->left = parentNode->left->right;
            else parentNode->left = NULL;
        }
    }
    else {
        if(parentNode->right->left== NULL)
            parentNode->right = parentNode->right->right;
        else if(parentNode->right->left == NULL)
            parentNode->right = parentNode->right->left;
        else parentNode->right = NULL;
    }   

    return 1;
};
