//
// Created by Guest on 09/10/2025.
//

#ifndef MYBST_H
#define MYBST_H
#include <vector>

struct MyNodeBST{
    int data;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};

class MyBST {
    int size;
    MyNodeBST* root;
    bool search(int data, MyNodeBST *current);
    void preorder(MyNodeBST* current, std::vector<int>& result);
    void inorder(MyNodeBST* current, std::vector<int>& result);
    void postorder(MyNodeBST* current, std::vector<int>& result);
    int height(MyNodeBST* current);

public:
    MyBST();
    ~MyBST();
    int length();
    bool isEmpty();
    bool search(int data);
    bool insert(int data);
    bool remove(int data);

    void preorder();
    void inorder();
    void postorder();

    void level();
    void visit(int type);

    int height();

    void ancestors(int data);

    int whatLevelAmI(int data);
};


#endif //MYBST_H