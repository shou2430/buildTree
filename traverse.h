#pragma once
#include "treeNode.h"
#include <queue>
#include <iostream>
#include <string>
#include <cmath>

class Node  {
public:
    Node(int x, int y, binaryTreeNode* root): x(x), y(y), ptr(root){}

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    binaryTreeNode* getTreeNode() {
        return this->ptr;
    }
private:
    int x, y;
    binaryTreeNode* ptr;
};


int getHeight(binaryTreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = 1 + getHeight(root->getLeft());
    int right = 1 + getHeight(root->getRight());

    if (left >= right)
        return left;
    else
        return right;
}



void BFS_printer(binaryTreeNode *root)
{
    std::queue<Node*> Queue;
    std::string output("");

    // 初始化二維陣列
    int h = getHeight(root);
    int ROW = 2 * h - 1;
    int COL = int(std::pow(2, h + 1));    
    std::string arr[ROW][COL];


    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = " ";
        }
    }

    // set root's value and its branches
    int middle = COL / 2 - 1;
    arr[0][middle] = std::to_string(root->getValue());
    
    if (root->hasLeft()) {
        arr[1][middle - int(std::pow(2, h - 1))] = "/";
        Queue.push(new Node(2, middle - int(std::pow(2, h - 1)) - 1, root->getLeft()));
    }
        
    if (root->hasRight()) {
        arr[1][middle + int(std::pow(2, h - 1))] = "\\";
        Queue.push(new Node(2, middle + int(std::pow(2, h - 1)) + 1, root->getRight()));
    }
        
    while (Queue.size() > 0) {
        Node *node = Queue.front();
        Queue.pop();
        int x = node->getX();
        int y = node->getY();
        binaryTreeNode *treeNode = node->getTreeNode();       
        arr[x][y] = std::to_string(treeNode->getValue());

        if (treeNode->hasLeft()) {
            arr[x + 1][y - 1] = "/";
            Queue.push(new Node(x + 2, y - 2, treeNode->getLeft()));
        }

        if (treeNode->hasRight()) {
            arr[x + 1][y + 1] = "\\";
            Queue.push(new Node(x + 2, y + 2, treeNode->getRight()));
        }
        delete node;
    }

    for (int i = 0; i < ROW ;i ++) {
        for (int j = 0; j < COL; j ++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}