#include "MOT.h"

// --------- Node implementation ---------
MOT::Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

int MOT::Node::getHeight() 
{
    if (!this) return -1;
    int lh = (left) ? left->getHeight() : -1;
    int rh = (right) ? right->getHeight() : -1;
    return 1 + max(lh, rh);
}

int MOT::Node::countElements() 
{
    if (!this) return 0;
    int lc = (left) ? left->countElements() : 0;
    int rc = (right) ? right->countElements() : 0;
    return 1 + lc + rc;
}

// --------- MOT implementation ---------
MOT::MOT() : root(nullptr) {}
MOT::~MOT() 
 {
    deleteTree(root);
    root = nullptr;
}

// --------- Insertions ---------

MOT::Node* MOT::insertUnbalanced(Node* node, int val) 
{
    if (!node) return new Node(val);

    if (val < node->data)
        node->left = insertUnbalanced(node->left, val);
    else
        node->right = insertUnbalanced(node->right, val);

    return node;
}

MOT::Node* MOT::insertBalanced(Node* node, int val) 
{
    if (!node) return new Node(val);

    if (val < node->data)
        node->left = insertBalanced(node->left, val);
    else
        node->right = insertBalanced(node->right, val);

    int balance = getBalance(node);

    if (balance > 1) 
    {
        if (val > node->left->data)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1) 
    {
        if (val < node->right->data)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void MOT::insertUnbalanced(int val) 
{
    root = insertUnbalanced(root, val);
}

void MOT::insertBalanced(int val) 
{
    root = insertBalanced(root, val);
}

int MOT::countLayer()
{
    if (!root) return 0;

    std::queue<Node*> q;
    q.push(root);
    q.push(nullptr);  

    int depth = 0;

    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();

        if (current == nullptr) 
        {
            depth++;  
            if (!q.empty())
                q.push(nullptr); 
        } else 
        {
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    return depth;
}

int MOT::countDepth()
{
    return countDepthHelper(root);
} 

void MOT::deleteElement(int val)
{
    root = deleteElement(root, val);
    cout << "Deleted " << val << " from the tree.\n";
}

void MOT::searchElement(int val)
{
    Node* result = searchElement(root, val);
    if(result)
        cout << "Found " << val << " in the tree.\n";
    else
        cout << val << " not found in the tree.\n";
}

MOT::Node* MOT::minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left)
        current = current->left;

    return current;
}

MOT::Node* MOT::write_to_file(Node* node, ofstream& file)
{
    if (!node) 
    {
        file << "# "; // Using '#' to denote null
        return nullptr;
    }

    file << node->data << " ";
    write_to_file(node->left, file);
    write_to_file(node->right, file);
    return node;
}

MOT::Node* MOT::read_from_file(Node* node, ifstream& file)
{
    string val;
    deleteTree(root); 
    root = nullptr;
    while (file >> val) 
    {
        if (val == "#")
            continue;  // skiping null markers
        
        int intVal = stoi(val);
        insertBalanced(intVal); // insert each value into the balanced tree
    }
    return root; // return the root of the balanced tree
}

// --------- Rotations ---------

MOT::Node* MOT::rotateLeft(Node* node) 
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

MOT::Node* MOT::rotateRight(Node* node) 
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

// --------- Balance Utilities ---------

int MOT::getBalance(Node* node) 
{
    if (!node) return 0;
    int lh = (node->left) ? node->left->getHeight() : -1;
    int rh = (node->right) ? node->right->getHeight() : -1;
    return lh - rh;
}

bool MOT::isBalanced(Node* node) 
{
    int diff = abs(getBalance(node));
    return diff < 2;
}

int MOT::countDepthHelper(Node *node)
{
    if (!node) return 0;

    int leftDepth = countDepthHelper(node->left);
    int rightDepth = countDepthHelper(node->right);

    return 1 + max(leftDepth, rightDepth);
}


// --------- Printing ---------

void MOT::printInOrder(Node* node) 
{
    if (!node) return;
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

void MOT::printTree(Node* node, int space, int indent) 
{
    if (!node) return;

    space += indent;
    printTree(node->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << node->data << "\n";
    printTree(node->left, space);
}

void MOT::printTreeTopDown(Node* node) 
{
    if (!node) return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

// Public wrappers
void MOT::printInOrder() 
{ 
    printInOrder(root); cout << endl; 
}
void MOT::printTree() 
{ 
    printTree(root); 
}
void MOT::printTreeTopDown() 
{ 
    printTreeTopDown(root); 
}

void MOT::deleteTree(Node *node)
{
    if (!node) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void MOT::write_to_file(const string &filename)
{
    ofstream file(filename);
    if (!file) 
    {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    write_to_file(root, file);
    file.close();
    cout << "Tree written to " << filename << endl;
}

void MOT::read_from_file(const string &filename)
{
    ifstream file(filename);
    if (!file) 
    {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    root = read_from_file(root, file);
    file.close();
    cout << "Tree read from " << filename << endl;
}

void MOT::printStats() 
{
    if (!root) 
    {
        cout << "Tree is empty.\n";
        return;
    }

    cout << "Height: " << root->getHeight() << endl;
    cout << "Total Nodes: " << root->countElements() << endl;
}


MOT::Node* MOT::deleteElement(Node *node, int val)
{
    if(!node)
        return node;
    if(val < node->data)
        node->left = deleteElement(node->left, val);
    else if(val > node->data)
        node->right = deleteElement(node->right, val);
    else    
    {
        // node with only one child or no child
        if(!node->left || !node->right)
        {
            Node* temp = (node->left) ? node->left : node->right;
            delete node;
            return temp;
        }

        // if node has two children
        Node* successor = minValueNode(node->right); // find smallest in right subtree
        node->data = successor->data; // replace data
        node->right = deleteElement(node->right, successor->data);
    }

    int balance = getBalance(node);

    if(balance > 1)
    {
        if(getBalance(node->left) < 0)
            node->left = rotateLeft(node->left);   // LR case
        return rotateRight(node);                  // LL case  
    }
    if(balance < -1)
    {
        if (getBalance(node->right) > 0)
            node->right = rotateRight(node->right); // RL case
        return rotateLeft(node);                    // RR case
    }
    return node;
}

MOT::Node *MOT::findSuccessor(Node *node, int val)
{
    Node* succ = nullptr;
    while (node) 
    {
        if (val < node->data) 
        {
            succ = node;
            node = node->left;
        } else 
        {
            node = node->right;
        }
    }
    return succ;
}

MOT::Node* MOT::findPredecessor(Node* node, int val) 
{
    Node* pred = nullptr;
    while (node) 
    {
        if (val > node->data) 
        {
            pred = node;
            node = node->right;
        } else 
        {
            node = node->left;
        }
    }
    return pred;
}

MOT::Node *MOT::searchElement(Node *node, int val)
{
    if(!node) return nullptr;

    if(node->data == val) 
        return node;
    if(val < node->data) 
        return searchElement(node->left, val);
    else
        return searchElement(node->right, val);
}

void MOT::findSuccessor(int val) 
{
    Node* result = findSuccessor(root, val);
    if (result) 
        cout << "Next greater than " << val << ": " << result->data << endl;
    else cout << "No successor found.\n";
}

void MOT::findPredecessor(int val) 
{
    Node* result = findPredecessor(root, val);
    if (result) 
        cout << "Previous less than " << val << ": " << result->data << endl;
    else cout << "No predecessor found.\n";
}


bool MOT::sameHeight(Node* root1, Node* root2) 
{
    return root1->getHeight() == root2->getHeight();
}

bool MOT::sameNodeCount(Node* root1, Node* root2) 
{
    return root1->countElements() == root2->countElements();
}

bool MOT::isEqual(Node* root1, Node* root2) 
{
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;

    return (root1->data == root2->data) &&
           isEqual(root1->left, root2->left) &&
           isEqual(root1->right, root2->right);
}

bool MOT::isEqual(MOT& other) 
{
    return isEqual(this->root, other.root);
}

bool MOT::sameHeight(MOT& other) 
{
    return this->root->getHeight() == other.root->getHeight();
}

bool MOT::sameNodeCount(MOT& other) 
{
    return this->root->countElements() == other.root->countElements();
}

