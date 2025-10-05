#include "MOT.h"
#include <iostream>

using namespace std;

int main1(int val, MOT& tree) 
{
    int n, value;

    cout << "How many values do you want to insert into the tree? ";
    cin >> n;

    cout << "\nEnter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        if (val == 1)
            tree.insertUnbalanced(value);
        else
            tree.insertBalanced(value);
    }

    cout << "\n✅ Tree built successfully!\n";

    cout << "\n========= In-Order Traversal =========\n";
    tree.printInOrder();

    cout << "\n========= Tree View (Sideways) =========\n";
    tree.printTree();

    cout << "\n========= Level-Order (Top Down) =========\n";
    tree.printTreeTopDown();

    cout << "\n========= Tree Stats =========\n";
    tree.printStats();
    cout << "Depth (recursive): " << tree.countDepth() << endl;
    cout << "Layer Count (level-order method): " << tree.countLayer() << endl;

    return 0;
}


void printMenu() 
{
    cout << "\n====== BINARY TREE MENU ======\n";
    cout << "1. Insert (Unbalanced)\n";
    cout << "2. Insert (Balanced)\n";
    cout << "3. Delete an element\n";
    cout << "4. Search an element\n";
    cout << "5. Find Successor\n";
    cout << "6. Find Predecessor\n";
    cout << "7. Print Tree (Sideways)\n";
    cout << "8. Print Tree (Level Order)\n";
    cout << "9. Print Tree (In-Order)\n";
    cout << "10. Tree Stats (Height + Node Count)\n";
    cout << "11. Compare With Another Tree (Structure and Data)\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() 
{
    MOT tree1, tree2;
    int choice, value;

    while (true) 
    {
        printMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1:
                main1(1, tree1);
                break;

            case 2:
                main1(2, tree1);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                tree1.deleteElement(value);
                cout << "\n========= In-Order Traversal =========\n";
                tree1.printInOrder();

                cout << "\n========= Tree View (Sideways) =========\n";
                tree1.printTree();

                cout << "\n========= Level-Order (Top Down) =========\n";
                tree1.printTreeTopDown();

                cout << "\n========= Tree Stats =========\n";
                tree1.printStats();
                cout << "Depth (recursive): " << tree1.countDepth() << endl;
                cout << "Layer Count (level-order method): " << tree1.countLayer() << endl;
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                tree1.searchElement(value);
                break;

            case 5:
                cout << "Enter value to find successor of: ";
                cin >> value;
                tree1.findSuccessor(value);
                break;

            case 6:
                cout << "Enter value to find predecessor of: ";
                cin >> value;
                tree1.findPredecessor(value);
                break;

            case 7:
                cout << "\nTree (Sideways View):\n";
                tree1.printTree();
                break;

            case 8:
                cout << "\nTree (Level Order View):\n";
                tree1.printTreeTopDown();
                break;

            case 9:
                cout << "\nTree (In-Order Traversal):\n";
                tree1.printInOrder();
                break;

            case 10:
                cout << "\nTree Stats:\n";
                tree1.printStats();
                cout << "Depth (Recursive): " << tree1.countDepth() << endl;
                cout << "Layer (Queue-based): " << tree1.countLayer() << endl;
                break;

            case 11:
                cout << "\nCreating another tree (tree2) for comparison...\n";

                // Build second tree
                cout << "Enter number of elements to insert in second tree: ";
                int n2;
                cin >> n2;

                for (int i = 0; i < n2; ++i) 
                {
                    cout << "Value " << i + 1 << ": ";
                    cin >> value;
                    tree2.insertBalanced(value);  // You can change to insertUnbalanced
                }

                cout << "\nComparing trees...\n";
                if (tree1.isEqual(tree2))
                    cout << "✅ Both trees are structurally and element-wise equal.\n";
                else
                    cout << "❌ Trees are not equal in structure or elements.\n";

                if (tree1.sameHeight(tree2))
                    cout << "✅ Trees have the same height.\n";
                else
                    cout << "❌ Trees differ in height.\n";

                if (tree1.sameNodeCount(tree2))
                    cout << "✅ Trees have the same number of nodes.\n";
                else
                    cout << "❌ Trees differ in number of nodes.\n";
                break;

            case 0:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
