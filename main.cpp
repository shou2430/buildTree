#include "traverse.h"

int main(){
    int rootVal, countEle = 1, isLeft, isRight;
    std::queue<binaryTreeNode*> treeQueue;

    std::cout << "請你輸入root的值：";
    std::cin >> rootVal;
    binaryTreeNode root(rootVal);
    

    std::cout << "請問第" << countEle << "個元素<root>有左兒子嗎<有:1, 無:0>:";
    std::cin >> isLeft;
    std::cout << "請問第" << countEle << "個元素<root>有右兒子嗎<有:1, 無:0>:";
    std::cin >> isRight;    
    
    if (isLeft)
        treeQueue.push(root.buildLeftChild());
    
    if (isRight)
        treeQueue.push(root.buildRightChild());

    if (isLeft || isRight)
        countEle++;
    
    // BFS
    while (treeQueue.size())
    {
        auto *ptr = treeQueue.front();
        std::cout << "請輸入第" << countEle << "個元素的值:";
        std::cin >> rootVal;
        ptr->setValue(rootVal);
        std::cout << "請問第" << countEle << "個元素有左兒子嗎<有:1,無:0>:";
        std::cin >> isLeft;
        if (isLeft)
        {
            ptr->buildLeftChild();
            treeQueue.push(ptr->getLeft());
        }
            
        std::cout << "請問第" << countEle << "個元素有右兒子嗎<有:1,無:0>:";
        std::cin >> isRight;   
        if (isRight)
        {
            ptr->buildRightChild();
            treeQueue.push(ptr->getRight());
        }     

        treeQueue.pop();
        countEle++;
    }

    BFS_printer(&root);    
}