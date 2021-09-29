#include <iostream>
#include <queue>

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

    /**
     * Preorder traversal is visiting current node first, and visit first, second node.
     */
    static void preOrder(Node* node) {
        cout << node->strData << ' '; // (1) process current node
        if(node->first != NULL) { preOrder(node->first); } // (2) process first node
        if(node->second != NULL) { preOrder(node->second); } // (3) process second node
    }

    /**
     * Inorder traversal is visiting first node first, and visit current, second node.
     */
    static void inOrder(Node* node) {
        if(node->first != NULL) { inOrder(node->first); } // (1) process first node
        cout << node->strData << ' '; // (2) process current node
        if(node->second != NULL) { inOrder(node->second); } // (3) process second node
    }

    /**
     * Postorder traversal is visiting first node first, and visit current, second node.
     */
    static void postOrder(Node* node) {
        if(node->first != NULL) { postOrder(node->first); } // (1) process first node
        if(node->second != NULL) { postOrder(node->second); } // (2) process second node
        cout << node->strData << ' '; // (3) process current node
    }

    /**
     * Postorder traversal is visiting by up-down, left-right order.
     *     BFS(Breadth-First Search)is using Postorder traversal.
     */
    static void levelOrder(Node* start) {
        if(!start) { return; }
        queue<Node*> qQueue;
        qQueue.push(start);
        while(!qQueue.empty()) {
            Node* h = qQueue.front();
            qQueue.pop();
            cout << h->strData << ' ';
            if(h->first != NULL) { qQueue.push(h->first); }
            if(h->second != NULL) { qQueue.push(h->second); }
        }
        cout << endl;
    }
};

int main() {
    Tree tree = Tree::newTree("hello");
    tree.add("hello", "aloha");
    tree.add("hello", "hola");
    tree.add("aloha", "gimmozzi");
    tree.add("aloha", "pizza");

    Tree::preOrder(tree.root); // result is "hello aloha gimmozzi pizza hola"
    cout << endl;
    Tree::inOrder(tree.root); // result is "gimmozzi aloha pizza hello hola"
    cout << endl;
    Tree::postOrder(tree.root); // result is "gimmozzi pizza aloha hola hello"
    cout << endl;
    Tree::levelOrder(tree.root); // result is "hello aloha hola gimmozzi pizza"
    return 0;
}