/**
 * @author Priyam Seth (Group 23)
 * Date Created - Nov 2nd, 2020
 * 
 * Here in this file, I will create the implementation of RBT
 * This is also one of my first program towards learning cpp
 * 
 * This code complies with the visualisation used by Sir in class
 * https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
 * 
*/

#include <iostream>

using namespace std;


/*

A red black tree
1. root must be black (black is 0 in this code)
2. No two red childs near to each other
3. Black depth equal
4. Take null leaves as black

We do coloring or rotation in the tree
to satisfy these properites

color code => 0 for black and 1 for red

*/

// First let's define a red black tree node
struct Node {
    Node *parent;
    Node *left;
    Node *right;

    // To store the values
    int key;

    // Take color black as 0 and color red as 1
    int color;
};

// A utility function to create a new BST node using value and color
struct Node *newNode(int val, int col)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp -> key = val;
    temp -> color = col;
    temp -> left = temp -> right = temp -> parent = nullptr;
    return temp;
}

// The head pointer or the root pointer which poitns to the root node
Node *rootPointer = newNode(100, 0);
// IMPORTANT! AT THE LEFT of this ROOTPointer, the root node will be stored



/* --- Then define some basic functions --- */

/**
 * @param Provide the node
 * 
 * @return the Parent of the node
 */
Node *getParent(Node *node) {
    if (node == nullptr) {
        return nullptr;
    } else {
        return node->parent;
    }
}

/**
 * @param Provide the node
 * 
 * @return the Parent of the Parent 
 */
Node *getGrandParent(Node *node) {
    return getParent(getParent(node));
}

/**
 * @param the node
 * 
 * @return the Sibing of the current node, or say the other child of it's parent
 */ 
Node *getSibling(Node *node) {
    Node *par = getParent(node);

    if (par == nullptr) {
        return nullptr;
    }

    // Check what kind of child it is
    if (par->left == node) {
        return par->right;
    } else {
        return par->left;
    }
}

/**
 * @param the node
 * 
 * @return the Uncle of the current node, or say the parents sibling
 */ 
Node *getUncle(Node *node) {
    Node *par = getParent(node);

    return getSibling(par);
}


/* --- Now define the rotations --- */

// Left rotation
void rotateLeft(Node *node) {

    // node -> right should not be empty take care while sending
    // As we are rotating about it

    Node *nn = node -> right; // Storing the right node, if nullptr means black
    Node *p = getParent(node); // Get the parent node

    node -> right = nn -> left;
    nn -> left = node;
    node -> parent = nn;

    // Handle other child/parent pointers.
    if (node -> right != nullptr) {
        node -> right -> parent = node;
    }

    // Now update the parent's node to the new node
    if(p != nullptr) {
        
        // Check what kind of child it was
        if (node == p -> left) {
            p -> left = nn;
        } else {
            p -> right = nn;
        }

        nn -> parent = p;

    } else {
        // Parent is null!!
        rootPointer -> left = nn;
        nn -> parent = nullptr;
    }
}

// Right rotation
void rotateRight(Node *node) {

    // node -> left should not be empty take care while sending
    // As we are rotating about it

    Node *nn = node -> left; // Storing the left node, if nullptr means black
    Node *p = getParent(node); // Get the parent node
    
    node -> left = nn -> right;
    nn -> right = node;
    node -> parent = nn;

    // Handle other child/parent pointers.
    if (node -> left != nullptr) {
        node -> left -> parent = node;
    }

    // Now update the parent's node to the new node
    if(p != nullptr) {
        
        // Check what kind of child it was
        if (node == p -> left) {
            p -> left = nn;
        } else {
            p -> right = nn;
        }

        nn -> parent = p;
    } else {
        // Parent got null update the rootPointer
        rootPointer -> left = nn;
        nn -> parent = nullptr;
    }
}




/* --- Searching --- */

/**
 * Searches the value in the tree and returns the first node with that value
 * @param root - The tree
 * @param val - The value to be searched
 * 
 * @return Node which has the values val
 */
Node *searchNode(Node *root, int val) {
    
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root -> key == val)
       return root;
    
    // Key is greater than root's key
    if (root -> key < val)
       return searchNode(root -> right, val);
 
    // Key is smaller than root's key
    return searchNode(root -> left, val);

}


/* --- Insertion --- */

/**
 * Recursilvely inserts the node in the tree
 * @param root - The root of the tree where to be inserted
 * @param node - The node to be inserted
 */
void simpleInsertion(Node *root, Node *node) {
    // root should not be nullptr

    // First check if the root is exhausted or not
    if (root != nullptr) {

        // Now we will check the key
        if (node -> key < root -> key) {
            // The new node values is smaller, so adding it to left of root

            if (root -> left == nullptr) {
                root -> left = node;
            } else {
                simpleInsertion(root -> left, node);
                return;
            }

        } else {
            // The new node values is greater, so adding it to the right of root
            
            if (root -> right == nullptr) {
                root -> right = node;
            } else {
                simpleInsertion(root -> right, node);
                return;
            }
        }
    }

    // If the function did not return insert new node
    node -> parent = root;
    node -> left = nullptr;
    node -> right = nullptr;
    node -> color = 1; // 1 means red as inserted node
}

/**
 * After the simple insertion, balance the tree starting at the inserted node
 * @param node - The node which was inserted 
 */
void repairInsertedTree(Node *node) {
    // Here we check for the insertion order and do the steps accordingly

    // Here we check for 4 conflicting cases that arise after insertion
    // Since the insertion is a red node, the black depth hasn't changed

    if (getParent(node) == nullptr) {
        // Ttrivial Case: Node has become the root node

        // Change the color to black
        node -> color = 0;
    
    } else if ( (getParent(node) -> color) == 0){
        // The parent is black
        // Nothing to do, tree is already balanced
    } else  if(getUncle(node) != nullptr && getUncle(node) -> color == 1) {
        // Case 2: c (node), p (parent), u (uncle) all are red and not null

        // So flip the colors and keep checking upwards
        getParent(node) -> color = 0;
        getUncle(node) -> color = 0;
        getGrandParent(node) -> color = 1;
        
        // Now repeat this step for g (grap Parent)
        repairInsertedTree(getGrandParent(node));
    } else {
        // Now solving the rotation cases
        
        // Case A If zig zag
        Node *p = getParent(node);
        Node *g = getGrandParent(node);

        if (g != nullptr) {
            if (node == p -> right && p == g -> left) {
                rotateLeft(p);
                node = node -> left;
            } else if(node == p -> left && p == g -> right) {
                rotateRight(p);
                node = node -> right;
            }
        }

        // Case B if zig zag it was fixed above, not fix double red
        Node *p2 = getParent(node);
        Node *g2 = getGrandParent(node);

        if (g2 != nullptr) {
            if (node == p2 -> left) {
                rotateRight(g2);
            } else {
                rotateLeft(g2);
            }

            p2 -> color = 0;
            g2 -> color = 1;

        }
    }
}


/**
 * INSERTS a node in the Red black tree and also updates the rootPointer if needed
 * 
 * @param The root of the tree in which you want to insert
 * @param The new node you want to insert
 * 
 * @return The parent of the inserted node
 */
Node *insertNode(Node *root, Node *node) {

    if (root == nullptr) {
        rootPointer -> left = node;
    }

    // First we simply insert the node recursively considering it as red
    simpleInsertion(root, node);

    // Now after insertion, we check if the tree is still valid and it has not gone into any problem
    repairInsertedTree(node);
    

    // Return the new created tree
    return root;
}

/* --- Deletion --- */

// Swap the values between node u and v
void swapValues(Node *u, Node *v) { 
    int temp;
    temp = u -> key; 
    u -> key = v -> key; 
    v -> key = temp; 
}

// Finds the predicissor of the node
// It loops right wards in the left child of the node to find the predicissor
Node *findPredecissor(Node *node) {

    // Take the left node
    Node *tnode = node -> left;

    while (tnode -> right != nullptr) {
        tnode = tnode -> right;
    }

    return tnode;
}

/**
 * Find the node with which the deleted node needs to be replaced
 * @param node - The node which has to deleted in the tree
 * 
 * @return The node if there is any node witch which it needs to be replaced or nullptr if leaf node
 */
Node *findNodeToReplace(Node *node) {
    // If leaf node
    if (node -> left == nullptr && node -> right == nullptr)
        return nullptr;
    
    // If both the children are present
    if (node -> left != nullptr && node -> right != nullptr) {
        return findPredecissor(node);
    }

    // Now if the child has only one child return that one
    if (node -> left == nullptr) {
        return node -> right;
    } else {
        return node -> left;
    }    
}


/**
 * Function to fix the doubly black nodes created while deletion
 * @param root - The root of the tree
 * @param node - The suspected doubly black node
 */
void fixDoubleBlack(Node *root, Node *node) {
    // Here we will fix the doubleBlackNode
    cout << "Fixing double black" << endl;

    // Recursively fix the problems till the root
    if (node == root) {
        return;
    }

    Node *s = getSibling(node);
    Node *p = getParent(node);

    if (s == nullptr)  {
        // sibling is null doubly black upwards
        fixDoubleBlack(root, p);
    } else {
        // It has a sibling

        // Check the color of the sibling
        if (s -> color == 1) {
            // sibling is red
        
        p -> color = 1; 
        s -> color = 0; 
        if (p-> left == s) {
            // sibling is the left child  
            rotateRight(p);
        } else { 
            // sibling is the right child
            rotateLeft(p); 
        }

        // Recursively check
        fixDoubleBlack(root, node);


        } else {
            // sibling is black

            // Now check if the sibling has a red child or not and do accordingly
            // Also according to the farther and nearer red child do accordingly
            bool hasARedChild = ((s-> left != nullptr && s -> left -> color == 1) || (s -> right != nullptr && s -> right -> color == 1));

            if (hasARedChild) {
                // Sibling has a red child!!!


                if (p -> left == s) {
                    // sibling is the left child

                    // check if the farther child is (left one is red or not)
                    if (s -> left != nullptr && s -> left -> color == 1) {

                        // one rotation can fix the problem
                        s -> left -> color = s -> color; 
                        s -> color = p -> color; 
                        rotateRight(p);
                        // Working perfectly case 2.3

                    } else {

                        // farther child is not red, double rotation needed
                        s -> right -> color = p -> color; 
                        rotateLeft(s);
                        rotateRight(p);
                        // Working perfectly case 2.2

                    }

                } else {
                    // sibling is the right child
                    
                    // check if farther one (right one is red or not)
                    if (s -> right != nullptr && s -> right -> color == 1) {
                        
                        // One rotation can fix the double blackness
                        s -> right -> color = s -> color; 
                        s -> color = p -> color; 
                        rotateLeft(p);
                        // Working perfectly case 2.3

                    } else {

                        // farther child is not red, so two rotations are needed
                        s -> left -> color = p -> color; 
                        rotateRight(s);
                        rotateLeft(p);
                        // Working perfectly case 2.2
                    }
                }   // End of what kind of child is sibling

                p -> color = 0;

            } else {
                // No red child in the sibling, both are black

                // Good to recolor
                s -> color = 1;
                if (p -> color == 0) {
                    //  Parent color is black
                    fixDoubleBlack(root, p);
                } else {
                    // Parent was red
                    p -> color = 0;
                }
            }
        }
    }
}   // End of fixing double black function


/**
 * DELETES the node in the tree
 * @param root - The root node of the tree
 * @param v - The node to be inserted in the RBT
 */
void deleteNode(Node* root, Node* v) {
    Node *u = findNodeToReplace(v);

    cout << "Deletion in preogress" << endl;

    bool uvBlack = ( (u == nullptr || u -> color == 0) && (v -> color == 0));
    Node *p = getParent(v);

    // If the node to be deleted is leaf node i.e. u is nullptr
    if (u == nullptr) {

        // check if root node
        if (v == root) {
            root = nullptr;
            rootPointer -> left = nullptr;

            // Done for this case
        } else {
            // Not a root node

            if (uvBlack) {
                // If it is a black in leaf node, it's deletion has left a doubly black null node
                // The deletion will leave a doubly black leaf node, so will take care of this first
                fixDoubleBlack(root, v);
            } else {

                if (getSibling(v) != nullptr) {
                    // Color the sibling red if it is not null
                    getSibling(v) -> color = 1;
                }
            }

            // After all set, good to remove the node
            if (getParent(v) -> right == v) {
                // It is a right child
                p -> right = nullptr;
            } else {
                p -> left = nullptr;
            }

        }

        delete v;
        return;
    }   // A leaf node case

    // The case when it has atleast one child
    if (v -> left == nullptr || v-> right == nullptr) {

        if (v == root) {
            // The root node
            // Make u the new root and delete v
            u -> parent = nullptr;
            rootPointer -> left = u;
            delete v;
        } else {
            // Not a root node and has atleast one child
            
            if (getParent(v) -> right == v) {
                // It was a right child
                p -> right = u;
                u -> parent = p;
            } else {
                // It was a left child
                p -> left = u;
                u -> parent = p;
            }
            
            delete v;   // Finally delete v after u has been placed in place of it
            
            if (uvBlack) {
                // If u and v both are black, black depth has decreased!
                fixDoubleBlack(root, u);
            } else {
                // u or v red, color u black
                u -> color = 0;
            }
        }

        return;
    }   // End of case when one child

    // The case when both the children are present
    swapValues(u, v);
    deleteNode(root, u); // This will become like the above two cases

}   // End of delete node function

/**
 * Delete the node in the tree by value
 * This calls the deleteNode function after searching the node to be deleted
 * 
 * @param root - The root of the BST
 * @param val - The value to be deleted
 */
void deleteByValue(Node *root, int val) {

    // Tree is empty, no node to delete
    if (root == nullptr) {
        return;
    }

    Node *v = searchNode(root, val);
    if (v == nullptr) {
        // This implies value not found
        cout << "No Node found to be deleted with value: " << val << endl;
        return;
    } else {
        cout << "Value " << (v -> key) << " found deleting it" << endl;

        // Now we will delete the node v
        deleteNode(root, v);
        cout << "Value deleted" << endl;
    }
}


/* --- Printing the Tree --- */

// Prints the tree in PostOrder
void printPostorder(Node *node) {
   if (node == nullptr)
      return;

   printPostorder(node -> left);
   printPostorder(node -> right);
   cout << node -> key << " ";
}

void printPostorderWithColor(Node *node) {
   if (node == nullptr)
      return;

   printPostorderWithColor(node -> left);
   printPostorderWithColor(node -> right);
   cout << node -> key << "(" << node -> color << ")" << " ";
}


// Prints the tree in Preorder
void printPreorder(Node* node) {
   if (node == nullptr)
      return;

   cout << node -> key << " ";
   printPreorder(node -> left);
   printPreorder(node -> right);
}

// Print the tree in preorder with color
void printPreorderWithColor(Node* node) {
   if (node == nullptr)
      return;

   cout << node -> key << "(" << node -> color << ")" << " ";
   printPreorderWithColor(node -> left);
   printPreorderWithColor(node -> right);
}


/* --- Range Queries --- */

int getRangeCount(Node *root, int low, int high) {
    if (root == nullptr)
        return 0;
    
    // Now check the key is in the range

    if (root -> key >= low && root -> key <= high) {
        return 1 + getRangeCount(root -> left, low, high) + getRangeCount(root -> right, low, high);
    }
    else  if (root -> key < low) {
        // Key got less, search for bigger ones in right
        return getRangeCount(root -> right, low, high);
    }
    else {
        // Key got more, search for smaller ones in left
        return getRangeCount(root -> left, low, high);
    }
}

int getRangeSum(Node *root, int low, int high) {
    if (root == nullptr)
        return 0;
    
    // Now check the key is in the range

    if (root -> key >= low && root -> key <= high) {
        return (root -> key) + getRangeSum(root -> left, low, high) + getRangeSum(root -> right, low, high);
    }
    else  if (root -> key < low) {
        // Key got less, search for bigger ones in right
        return getRangeSum(root -> right, low, high);
    }
    else {
        // Key got more, search for smaller ones in left
        return getRangeSum(root -> left, low, high);
    }
}

// main function -
// where the execution of program begins
int main() {

    struct Node *root = nullptr;

    insertNode(root, newNode(20, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(30, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(70, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(60, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(80, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(20, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(40, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(10, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(5, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(12, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(50, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(17, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(18, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(6, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(11, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(14, 1));
    root = rootPointer -> left;

    insertNode(root, newNode(75, 1));
    root = rootPointer -> left;

    // deleteByValue(root, 3);
    // root = rootPointer -> left;

    // deleteByValue(root, 10);
    // root = rootPointer -> left;

    cout << "Already inserted Nodes" << endl;
    printPreorder(root);
    cout << endl;
    
    int choice = 1;
    int inp = 0;
    int cr = 1, sr = 0, li=0, hi=0;
    double avr = 0;

    while (1) {
        cout << endl;
        cout << "Enter 1 for insertion: " << endl;
        cout << "Enter 2 for deletion: " << endl;
        cout << "Enter 3 for searching: " << endl;
        cout << "Enter 4 for Range Average: " << endl;
        cout << "Enter 5 for preorder printing: " << endl;
        cout << "Enter 6 for exit: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Insertion

            cout << "Enter the Value to be inserted: ";
            cin >> inp;

            insertNode(root, newNode(inp, 1));
            root = rootPointer -> left;

            // Print in Preorder
            printPreorderWithColor(root);
            cout << endl;
            
            break;
        case 2:
            // Deletion
            cout << "Enter the value to be deleted: ";
            cin >> inp;

            deleteByValue(root, inp);
            root = rootPointer -> left;

            // Print in Preorder
            printPreorderWithColor(root);
            cout << endl;
            
            break;
        case 3:
            // Searching
            cout << "Enter the Values to be searched for: ";
            cin >> inp;

            if (searchNode(root, inp) != nullptr) {
                cout << "Value Found " << inp << endl;
            } else {
                cout << "Value Not Found!" << endl;
            }

            break;
        case 4:

            cout << "Enter the Range low and then High seprated by space: " << endl;
            cin >> li >> hi;

            cr = getRangeCount(root, li, hi);
            sr = getRangeSum(root, li, hi);

            if (cr == 0) {
                // Zero values found
                cout << "Average on numbers in range " << li << " " << hi << " is: 0" << endl;
            } else {
                avr =  ((double) sr) / cr;
                cout << "Average on numbers in range " << li << " " << hi << " is: " << avr << endl;
            }

            break;
        case 5:
            // Print in Preorder
            printPreorderWithColor(root);
            cout << endl;

            break;
        case 6:
            exit(1);
            
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }


    // Print the tree in preorder
    printPreorder(root);
    cout << endl;

    printPreorderWithColor(root);
    cout << endl;

    return 0;
}
