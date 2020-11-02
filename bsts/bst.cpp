/**
 * @author Priyam Seth
 * 
 * Here in this file, I will create a simple BST implementations
 * This is also my first program towards learning cpp
 * 
*/


#include <iostream>
using namespace std;

// Starting writing the program
// Generally we define a POJO class in Java, but here we create structures just like object
struct nod
{
    // nod is actually node with left and right children
    int info;
    struct nod *l;
    struct nod *r;
} *r;

class BST
{
private:
    /* data */
public:
    void insert(nod *, nod *);
    void show(nod *, int);

    BST() {
        r = NULL;
    }
};

void BST::insert(nod *tree, nod *newnode) {

    if (r == NULL) {
        // Node is empty insert at the root
        r = new nod;
        r->info = newnode->info;
        r->l = NULL;
        r->r = NULL;

        cout << "Root node is added" << endl;
        return;
    }

    if (tree->info == newnode->info) {
        // Duplicate numbers not allowed in BST

        cout << "Node is already present in tree" << endl;
        return;
    }

    if(tree->info > newnode->info) {
        // This means the new node is smaller than the current node

        if (tree->l != NULL) {
            // If the left node is occupied, move to the next one
            insert(tree->l, newnode);
        }
        else {
            tree->l = newnode;
            (tree->l)->l = NULL;
            (tree->l)->r = NULL;
            cout << "Node Added to the left" << endl;
        }
    }
    else {
        // This means the new node is greather than the current node

        if (tree->r != NULL) {
            // If the node is already occupied
            insert(tree->r, newnode);
        }
        else {
            tree->r = newnode;
            (tree->r)->l = NULL;
            (tree->r)->l = NULL;
            cout << "Node is added to the right" << endl;
        }
    }
}   // End of insert


void BST::show(nod *ptr, int level)//print the tree
{
   int i;
   if (ptr != NULL)
   {
      show(ptr->r, level+1);
      cout<<endl;
      if (ptr == r)
         cout<<"Root→: ";
      else
      {
         for (i = 0;i < level;i++)
         cout<<" ";
      }
      cout<<ptr->info;
      show(ptr->l, level+1);
   }
}



int main() {
    int c, n, item;
    BST bst;

    nod *t;

     while (1)
   {
      cout<<"1.Insert Element "<<endl;
      cout<<"2.Delete Element "<<endl;
      cout<<"3.Search Element"<<endl;
      cout<<"4.Inorder Traversal"<<endl;
      cout<<"5.Preorder Traversal"<<endl;
      cout<<"6.Postorder Traversal"<<endl;
      cout<<"7.Display the tree"<<endl;
      cout<<"8.Quit"<<endl;
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c)
      {
         case 1:
            t = new nod;
            cout << "Enter the number to be inserted : ";
            cin >> t->info;
            bst.insert(r, t);
            break;
         case 2:
            if (r == NULL)
            {
               cout<<"Tree is empty, nothing to delete"<<endl;
               continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>n;
            // bst.del(n);
            break;
         case 3:
            cout<<"Search:"<<endl;
            cin>>item;
            // bst.search(r,item);
            break;
         case 4:
            cout<<"Inorder Traversal of BST:"<<endl;
            // bst.inorder(r);
            cout<<endl;
            break;
         case 5:
            cout<<"Preorder Traversal of BST:"<<endl;
            // bst.preorder(r);
            cout<<endl;
            break;
         case 6:
            cout<<"Postorder Traversal of BST:"<<endl;
            // bst.postorder(r);
            cout<<endl;
            break;
         case 7:
            cout<<"Display BST:"<<endl;
            bst.show(r,1);
            cout<<endl;
            break;
         case 8:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}
