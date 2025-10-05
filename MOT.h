#ifndef MOT_H
#define MOT_H

#include <iostream>
#include <queue>
using namespace std;

class MOT 
{
private:
    struct Node 
    {
        int data;
        Node *left;
        Node *right;

        Node(int val = 0);
        int getHeight();
        int countElements();
        
    };

    Node* root;

    // Recursive helpers
    Node* insertUnbalanced(Node* node, int val);
    Node* insertBalanced(Node* node, int val);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* minValueNode(Node* node);
    int getBalance(Node* node);
    bool isBalanced(Node* node);
    int countDepthHelper(Node* node) ;

    Node* deleteElement(Node* node, int val);
    Node* findSuccessor(Node* node, int val);
    Node* findPredecessor(Node* node, int val);
    Node* searchElement(Node* node, int val);

    void printInOrder(Node* node);
    void printTreeTopDown(Node* node);
    void printTree(Node* node, int space = 0, int indent = 4);

    bool sameHeight(Node* root1, Node* root2);
    bool sameNodeCount(Node* root1, Node* root2);
    bool isEqual(Node* root1, Node* root2);

public:
    MOT();
    ~MOT();   

    MOT(const MOT&) = delete;
    MOT& operator=(const MOT&) = delete;
    
    int countLayer();
    int countDepth();
    void deleteElement(int val);       
    void searchElement(int val);       
    void insertBalanced(int val);      
    void findSuccessor(int val);
    void findPredecessor(int val);
    void insertUnbalanced(int val);   

    void printTree();
    void printStats();
    void printInOrder();
    void printTreeTopDown();
    void deleteTree(Node* node);


    bool isEqual(MOT& other);
    bool sameHeight(MOT& other);
    bool sameNodeCount(MOT& other);
    
   
};
#endif
