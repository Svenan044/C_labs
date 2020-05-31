#include "TreeNode.h"

int TreeNode::getNodeValue() {
    return value;
}

TreeNode* TreeNode::getLeftNode() {
    return leftNode;
}

TreeNode* TreeNode::getRightNode() {
    return rightNode;
}

void TreeNode::setNodeValue(int num) {
    value = num;
}

int TreeNode::getLeftNodeValue() {
    return leftNode->value;
}

void TreeNode::setLeftNode(TreeNode* node) {
    leftNode = node;
}

void TreeNode::setLeftNodeValue(int value) {
    leftNode->value = value;
}

int TreeNode::getRightNodeValue() {
    return rightNode->value;
}

void TreeNode::setRightNode(TreeNode* node) {
    rightNode = node;
}
void TreeNode::setRightNodeValue(int value) {
    rightNode->value = value;
}
