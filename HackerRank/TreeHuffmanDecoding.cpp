/*
Huffman coding构造树的过程就是堆Heap的过程
只有叶子节点（左右子树=NULL）含有效字母，
*/
void decode_huff(node * root, string s) {
    node* cur = root;
    for(size_t i=0; i<s.size(); ++i) {
        if(s[i]=='0') {
            if(cur->left==nullptr) {
                cout << cur->data;
                cur = root;
            }
            cur = cur->left;
        } else {
            if(cur->right==nullptr) {
                cout << cur->data;
                cur = root;
            }
            cur = cur->right;
        }
    }
    
    cout << cur->data;
}
