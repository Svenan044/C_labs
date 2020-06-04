#include "BinaryTree.h"

void BinaryTree::Insert(int value, TreeNode* node) {
    if (node->getNodeValue() < value) {
        if (node->getRightNode() != nullptr) {
            Insert(value, node->getRightNode());
        }
        else {
            TreeNode* newNode = new TreeNode;
            node->setRightNode(newNode);
            node->setRightNodeValue(value);
        }
    }
    else if (node->getNodeValue() > value) {
        if (node->getLeftNode() != nullptr) {
            Insert(value, node->getLeftNode());
        }
        else {
            TreeNode* newNode = new TreeNode;
            node->setLeftNode(newNode);
            node->setLeftNodeValue(value);
        }
    }
}

TreeNode* BinaryTree::Search(int value, TreeNode* node) {
        if (node != nullptr){
            if (node->getNodeValue() > value) {
                node = node->getLeftNode();
                Search(value, node);
            }
            else if (node->getNodeValue() < value) {
                node = node->getRightNode();
                Search(value, node);
            }
            else if (node->getNodeValue() == value) {
                return node;
            }
        }
        else {
            return nullptr;
        }
    }

void BinaryTree::Insert(int value) {
    if (root != nullptr) {
        Insert(value, root);
    }
    else {
        TreeNode* newNode = new TreeNode;
        newNode->setNodeValue(value);
        root = newNode;
    }
}

TreeNode* BinaryTree::Search(int value) {
    return Search(value, root);
}

void BinaryTree::CreateMinimalBST(int* array, int firstIndex, int secondIndex) {
    int midIndex = (secondIndex + firstIndex)/2;
    Insert(array[midIndex]);
    if (midIndex < secondIndex){
        CreateMinimalBST(array, midIndex+1, secondIndex);
    }
    if (midIndex > firstIndex){
        CreateMinimalBST(array, firstIndex, midIndex-1);
    }
}