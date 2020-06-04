#pragma once
#include "TreeNode.h"

class BinaryTree{
    private:
        TreeNode* root;
        BinaryTree* tree;
        void Insert(int value, TreeNode* node);
        TreeNode* Search(int value, TreeNode* node);

    public:
        BinaryTree() {
            root = nullptr;
        };
        ~BinaryTree();
        void Insert(int value);
        TreeNode* Search(int value);
        void CreateMinimalBST(int* array, int firstIndex, int secondIndex);
};