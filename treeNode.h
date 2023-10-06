#pragma once
#include <string>

class binaryTreeNode {
public:
    binaryTreeNode(int value = 0) : value(value), left(nullptr), right(nullptr){}
    
    binaryTreeNode* buildLeftChild(){
        this->left = new binaryTreeNode();
        return this->left;
    }

    binaryTreeNode* buildRightChild(){
        this->right = new binaryTreeNode();
        return this->right;
    }    

    void setValue(int num) {
        this->value = num;
    }
    
    int getValue() const {
        return this->value;
    }

    bool hasLeft() const {
        if (this->left)
        {
            return true;
        }
        return false;
    }

    bool hasRight() const {
        if (this->right)
        {
            return true;
        }
        return false;
    }

    binaryTreeNode* getLeft() const { return this->left; }
    binaryTreeNode* getRight() const { return this->right; }

    ~binaryTreeNode() {
        delete left;
        delete right;
    }

private:
    int value;
    binaryTreeNode *left, *right;
};