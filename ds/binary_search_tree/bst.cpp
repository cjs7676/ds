#include <iostream>

using namespace std;

// Structure for a BST Node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = new struct Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with given key in BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function to do inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to do postorder traversal of BST
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// Function to do preorder traversal of BST
void preorder(struct Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to delete a node with the given key in BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (root->key > key) {
        root->left = deleteNode(root->left, key);
        return root;
    } else if (root->key < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }

    if (root->left == NULL) {
        struct Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        struct Node* temp = root->left;
        delete root;
        return temp;
    } else {
        struct Node* succParent = root;
        struct Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->key = succ->key;
        delete succ;
        return root;
    }
}

// Function to search a key in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

// Driver Code
int main() {
    struct Node* root = NULL;

    // Inserting values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the BST
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nPreorder: ";
    preorder(root);

    // Searching in the BST
    int keyToSearch = 60;
    struct Node* searchResult = search(root, keyToSearch);
    if (searchResult == NULL)
        cout << "\n" << keyToSearch << " not found" << endl;
    else
        cout << "\n" << keyToSearch << " found" << endl;

    // Deleting a node from the BST
    int keyToDelete = 40;
    root = deleteNode(root, keyToDelete);
    cout << "\nBST after deleting " << keyToDelete << ": ";
    inorder(root);

    return 0;
}
