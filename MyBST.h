//
// Created by Guest on 09/10/2025.
//

#ifndef MYBST_H
#define MYBST_H
#include <vector>
#include <string>

struct MyNodeBST{
    int data;
    std::vector<std::string> ip;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data, std::vector<std::string> ip){
        this->ip=ip;
        this->data=data;
        this->left=this->right=nullptr;
    }
    MyNodeBST(int data, std::string one_ip) {
        this->data=data;
        this->ip.push_back(one_ip);
        this->left=this->right=nullptr;
    }
};

class MyBST {
    int size;
    MyNodeBST* root;
    bool search(int data, MyNodeBST *current);
    void preorder(MyNodeBST* current, std::vector<int>& result);
    void inorder(MyNodeBST* current, std::vector<std::pair<std::vector<std::string>,int>>& result);
    void postorder(MyNodeBST* current, std::vector<int>& result);
    int height(MyNodeBST* current);
    void destroyNode(MyNodeBST* current);

public:
    MyBST();
    ~MyBST();
    int length();
    bool isEmpty();
    bool search(int data);
    bool insert(int data, std::string ip);
    bool remove(int data);

    void preorder();
    void inorder(int num);
    void postorder();

    void level();

    int height();

    void ancestors(int data);

    int whatLevelAmI(int data);
};


#endif //MYBST_H