#include <iostream>

using namespace std;

/**
 * This is simple example of tree.
 */

// As Node has two children, this tree is called a binary tree.
struct Node {
    string strData;
    Node* first;
    Node* second;
};

struct Tree {
    Node* root;

    // Makes new tree and returns it.
    static Tree newTree(const string& strRootData) {
        Tree tree;
        tree.root = new Node{strRootData, NULL, NULL};
        return tree;
    }

    // Find node with given data from given root and returns it.
    static Node* find(Node* root, const string& strData) {
        if(root == NULL) { return NULL; }
        if(root->strData == strData) { return root; }

        Node* resultOfFirst = Tree::find(root->first, strData);
        if(resultOfFirst == NULL) {
            return Tree::find(root->second, strData);
        }
        return resultOfFirst;
    }

    // Add new child under given parent.
    bool add(const string& strParentData, const string& strChildData) {
        Node* target = Tree::find(root, strParentData);
        if(!target) { return false; }
        if(target->first && target->second) {
            return false;
        } else if(!target->first) {
            target->first = new Node{strChildData, NULL, NULL};
        } else if(!target->second) {
            target->second = new Node{strChildData, NULL, NULL};
        }
        return true;
    }
};

int main() {
    Tree tree = Tree::newTree("hello");
    tree.add("hello", "aloha");
    tree.add("hello", "hola");
    tree.add("aloha", "gimmozzi");
    tree.add("aloha", "pizza");
    return 0;
}