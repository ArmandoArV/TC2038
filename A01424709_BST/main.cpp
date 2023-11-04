#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode* &root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    if (value < root->value) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->value == value) {
        return true;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    std::cout << root->value << " ";
    printInOrder(root->right);
}

void printInRange(TreeNode* root, int lower, int upper) {
    if (root == nullptr) {
        return;
    }

    if (root->value >= lower && root->value <= upper) {
        std::cout << root->value << " ";
    }

    printInRange(root->left, lower, upper);
    printInRange(root->right, lower, upper);
}

int main() {
    TreeNode* root = nullptr;

    // Insert some values into the Binary Search Tree
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);

    // Search for a specific value in the BST
    if (search(root, 10)) {
        std::cout << "The value 10 is in the BST" << std::endl;
    } else {
        std::cout << "The value 10 is not in the BST" << std::endl;
    }

    // Print all values of the BST in ascending order
    std::cout << "The values of the BST in ascending order are:" << std::endl;
    printInOrder(root);

    // Print values in a given range of the BST
    std::cout << std::endl;
    std::cout << "The values in the range [2, 12] are:" << std::endl;
    printInRange(root, 2, 12);

    return 0;
}
