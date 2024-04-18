#include <bits/stdc++.h>
using namespace std;

class BinarySearchTree {
    int value;
    BinarySearchTree *left, *right;

public:
    BinarySearchTree(int value) {
        this->value = value;
        left = right = NULL;
    }

    void inorder(BinarySearchTree *root) {
        if (!root)
            return

        inorder(root->left);
        cout << root->value << ' ';
        inorder(root->right);
    }

    BinarySearchTree* _delete(BinarySearchTree *root, int value) {
        if (!root)
            return root;

        if (value > root->value)
            root->right = _delete(root->right, value);
        else if (value < root->value)
            root->left = _delete(root->left, value);
        else {
            if (!root->left && !root->right)
                return NULL;
            else if (!root->left) {
                BinarySearchTree *temp = root->right;
                free(root);
                return temp;
            }
            else if (!root->right) {
                BinarySearchTree *temp = root->left;
                free(root);
                return temp;
            }

            BinarySearchTree *temp = min(root->right);
            root->value = temp->value;
            root->right = _delete(root->right, temp->value);
        }
    }

    BinarySearchTree* insert(BinarySearchTree *root, int value) {
        if (!root)
            return new BinarySearchTree(value)

        if (value > root->value)
            root->right = insert(root->right, value);
        else if (value < root->value)
            root->left = insert(root->left, value);

        return root;
    }

    BinarySearchTree* min(BinarySearchTree *root) {
        BinarySearchTree *curr = root;
        while (curr && !curr->left)
            curr = curr->left;
        return curr;
    }

    BinarySearchTree* search(BinarySearchTree *root, int value) {
        if (!root || root->value == value)
            return root;

        if (value > root->value)
            return search(root->right, value);
        return search(root->left, value);
    }
}
