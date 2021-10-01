#include <iostream>

using namespace std;

/**
 * BST(Binary Search Tree) is a tree created by following rule:
 *     value of first node <= value of current node <= value of second node
 */

struct Node {
    int nData;
    Node* first;
    Node* second;
};

struct BST {
    Node* root;

// static:
    static BST newBST(int nData) {
        BST tree;
        tree.root = new Node{nData, NULL, NULL};
        return tree;
    }

// public:
    /**
     * Public methods uses private methods implemented recursively.
     */
    Node* find(int nData) {
        return this->findImpl(this->root, nData);
    }

    void insert(int nData) {
        if(this->root == NULL) {
            this->root = new Node{nData, NULL, NULL};
        } else {
            this->insertImpl(this->root, nData);
        }
    }

    void del(int nData) {
        this->root = this->delImpl(this->root, nData);
    }

    void print() {
        this->inOrder(this->root);
    }

    /**
     * If the elements of BST are skewed to the left, rotating them to the right will help improve performance.
     */
    void rotateRight() {
        if(!this->root->first) { return; }
        Node* rootTemp = this->root;
        this->root = this->root->first;
        rootTemp->first = this->root->second;
        this->root->second = rootTemp;
    }

    /**
     * If the elements of BST are skewed to the right, rotating them to the left will help improve performance.
     */
    void rotateLeft() {
        if(!this->root->second) { return; }
        Node* rootTemp = this->root;
        this->root = this->root->second;
        rootTemp->second = this->root->first;
        this->root->first = rootTemp;
    }

private:
    /**
     * Finding one element.
     */
    Node* findImpl(Node* target, int nData) {
        // if target is the one, returns target.
        if(target->nData == nData) { return target; }

        // if given data is smaller than target's data, find element in target's left-subtree.
        if(target->nData > nData) { return this->findImpl(target->first, nData); }

        // if given data is bigger than target's data, find element in target's right-subtree.
        if(target->nData < nData) { return this->findImpl(target->second, nData); }

        // if node is not found.
        return NULL;
    }

    /**
     * Visiting BST by in-order traversal is same as visiting element by ascending order.
     */
    void inOrder(Node* node) {
        if(node->first != NULL) { this->inOrder(node->first); }
        cout << node->nData << ' ';
        if(node->second != NULL) { this->inOrder(node->second); }
    }

    /**
     * Inserting given data to target tree.
     */
    void insertImpl(Node* target, int nData) {
        // if given data is smaller than target's data and target's left is null, create new node in left-side.
        if(target->first == NULL && target->nData > nData) {
            target->first = new Node{nData, NULL, NULL};

        // if given data is bigger than target's data and target's left is null, create new node in right-side.
        } else if(target->second == NULL && target->nData < nData) {
            target->second = new Node{nData, NULL, NULL};

        // if given data is smaller than target's data and target's left is not null, find place in target's left-subtree.
        } else if(target->nData > nData) {
            this->insertImpl(target->first, nData);

        // if given data is bigger than target's data and target's right is not null, find place in target's right-subtree.
        } else if(target->nData < nData) {
            this->insertImpl(target->second, nData);

        // this would be a case that given data is same with target's data, place element between target and target's left-subtree.
        } else {
            target->first = new Node{nData, target->first, NULL};
        }
    }

    /**
     * Successor is a node that is bigger than target's data, but smallest one in target's right-subtree.
     *     therefore, the successor must be the leftmost node in the right-subtree of the target.
     *     so, successor can't have left-child.
     */
    Node* successor(Node* target) {
        auto cur = target->second;
        while(cur && cur->first != NULL) { cur = cur->first; }
        return cur;
    }

    /**
     * Deletes the node containing the given data from the given tree and returns the tree with data deleted.
     */
    Node* delImpl(Node* target, int nData) {
        // if target is null, returns null.
        if(!target) { return NULL; }

        // if given data is bigger than target's data, deletes data from target's right-subtree and allocates the tree with data deleted to target's right-child.
        if(target->nData < nData) {
            target->second = this->delImpl(target->second, nData);

        // if given data is smaller than target's data, deletes data from target's left-subtree and allocates the tree with data deleted to target's left-child.
        } else if(target->nData > nData) {
            target->first = this->delImpl(target->first, nData);

        // if given data is same with target's data.
        } else {
            // if target's left-child is null or right-child is null too.
            if(!target->first) {
                // as target's right-child must replace target, save target's right-child.
                //     if right-child is null, null is saved, and therefore target will be null.
                Node* temp = target->second;
                delete target;
                return temp;
            }

            // if target's right-child is null.
            if(!target->second) {
                // as target's left-child must replace target, save target's right-child.
                Node* temp = target->first;
                delete target;
                return temp;
            }

            // find successor node.
            Node* successorNode = this->successor(target);
            // replace target's data with successor node's data.
            target->nData = successorNode->nData;
            // deletes successor node's data from target's right-subtree and allocates the tree with successor node's data deleted to target's right-child.
            target->second = this->delImpl(target->second, successorNode->nData);
        }
        return target;
    }
};

int main() {
    BST bst = BST::newBST(10);
    bst.insert(5);
    bst.insert(11);
    bst.insert(6);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(8);
    bst.insert(7);
    bst.insert(9);

    bst.print(); // result is "1 2 3 4 5 6 7 8 9 10 11"
    cout << endl;

    bst.del(5);
    bst.print(); // result is "1 2 3 4 6 7 8 9 10 11"
    cout << endl;

    bst.rotateRight();
    bst.print(); // result is "1 2 3 4 6 7 8 9 10 11"
    cout << endl;

    bst.rotateLeft();
    bst.print(); // result is "1 2 3 4 6 7 8 9 10 11"
    cout << endl;

    return 0;
}