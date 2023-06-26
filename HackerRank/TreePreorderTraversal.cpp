void preOrder(Node *root) {
        std::cout << root->data << ' ';
        if(root->left!=nullptr) preOrder(root->left);
        if(root->right!=nullptr) preOrder(root->right);
}