#include <iostream>

using namespace std;


/*

A red black tree
1. root must be black
2. No two red childs near to each other
3. Black depth equal
4. Take null leaves as black

We do coloring or rotation in the tree
to satisfy these properites

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

// A utility function to create a new BST node
struct Node *newNode(int val, int col)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp -> key = val;
    temp -> color = col;
    temp -> left = temp -> right = temp -> parent = nullptr;
    return temp;
}

Node *rootPointer = newNode(100, 0);
// AT THE LEFT of this ROOTPointer, the root node will be stored

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


Node *getUncle(Node *node) {
    Node *par = getParent(node);

    return getSibling(par);
}


/* --- Now define the rotations --- */
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

void rotateRight(Node *node) {

    // node -> right should not be empty take care while sending
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

/* --- Insertion --- */

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
        
        // Case A
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

        // Case B
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
 * Take care that root isn't empty, if it is empty simply add it to newNode
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



void printPostorder(Node *node) {
   if (node == nullptr)
      return;

   printPostorder(node -> left);
   printPostorder(node -> right);
   cout << node -> key << " ";
}

void printPreorder(Node* node) {
   if (node == NULL)
      return;

   cout << node -> key << " ";
   printPreorder(node -> left);
   printPreorder(node -> right);
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


    // // prints hello world
    // int choice = 1;
    // Node *tree;
    // tree = nullptr;

    // while (1) {
    //     cout << "Enter 1 for insertion: " << endl;
    //     cout << "Enter 2 for deletion: " << endl;
    //     cout << "Enter 3 for searching: " << endl;
    //     cout << "Enter 4 for exit: " << endl;
    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         Node *n, nl;
    //         n = &nl;

    //         n->key = choice;

    //         cout << (tree == nullptr) <<endl;

    //         // insertNode(tree, n);
    //         break;

    //     case 4:
    //         exit(1);
        
    //     default:
    //         cout << "Invalid choice" << endl;
    //         break;
    //     }
    // }


    printPreorder(root);

    return 0;
}
