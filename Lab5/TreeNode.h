#pragma once
class  TreeNode
{
    private:
        int value;
        TreeNode* leftNode;
        TreeNode* rightNode;

    public:
        TreeNode() {
            value = int();
            leftNode = nullptr;
            rightNode = nullptr;
        }

        int getNodeValue();
        TreeNode* getLeftNode();
        TreeNode* getRightNode();
        void setNodeValue(int num);
        int getLeftNodeValue();
        void setLeftNode(TreeNode* node);
        void setLeftNodeValue(int value);
        int getRightNodeValue();
        void setRightNode(TreeNode* node);
        void setRightNodeValue(int value);
};