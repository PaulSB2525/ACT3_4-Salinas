//
// Created by Guest on 09/10/2025.
//

//Paul Aureliano Sarmiento Baldenebro
//A00227824

//ref "https://www.youtube.com/playlist?list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q"

#include "MyBST.h"

#include <iostream>
#include <queue>
#include <vector>

MyBST::MyBST() {
    this->root = nullptr;
    this->size = 0;
}

int MyBST::length() {
    return this->size;
}

bool MyBST::isEmpty() {
    return this->size==0;
}

/*bool MyBST::search(int data) {
    MyNodeBST* current=this->root;
    while(current!=nullptr) {
        if (current->data == data) {
            return true;
        }if (current->data > data) {
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return false;
}*/

bool MyBST::search(int data, MyNodeBST *current) {             //O(h)
    if (current==nullptr) {
        return false;
    }
    if (current->data == data) {
        return true;
    }
    if (current->data > data) {
        return search(data, current->left);
    }
    if (current->data < data) {
        return search(data, current->right);
    }
}

bool MyBST::search(int data) {
    return search(data, this->root);
}

bool MyBST::remove(int data) {              //O(h)
    if (this->root == nullptr) {
        return false;
    }
    MyNodeBST *current = this->root;
    MyNodeBST *aux = nullptr;

    while (current != nullptr && current->data != data) {
        aux = current;
        if (current->data == data) {
            return false;
        }
        if (current->data > data) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
    if (current == nullptr) {
        return false;
    }
    if (current->left != nullptr && current->right != nullptr) {
        MyNodeBST *pred = current->left;
        MyNodeBST *predAux = current;
        while (pred->right != nullptr) {
            predAux=pred;
            pred = pred->right;
        }
        current -> data = pred->data;
        current = pred;
        aux = predAux;
    }
    MyNodeBST *child = nullptr;
    if (current->left != nullptr) {
        child = current->left;
    }else {
        child = current->right;
    }
    if (aux == nullptr) {
        delete this->root;
        this->root = child;
    }else {
        if (aux->left == current) {
            aux->left = child;
        }else {
            aux->right = child;
        }
        delete current;
    }
    this->size--;
    return true;
}

bool MyBST::insert(int data, std::string ip) {      //O(h)
    if (this->root == nullptr) {
        this->root = new MyNodeBST(data, ip);
        this->size++;
        return true;
    }
    MyNodeBST *current = this->root;
    MyNodeBST *aux = nullptr;
    while (current != nullptr) {
        aux = current;
        if (current->data == data) {
            current->ip.push_back(ip);
            return true;
        }
        if (current->data > data) {
            current = current->left;
        }else {
            current = current->right;
        }
    }

    if (aux->data>data) {
        aux->left=new MyNodeBST(data,ip);
    }else {
        aux->right =new MyNodeBST(data,ip);
    }
    this->size++;
    return true;

}

void MyBST::preorder() {
    std::vector<int> result;
    preorder(this->root,result);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << ",";
    }
}

void MyBST::preorder(MyNodeBST* current, std::vector<int>& result) {        //O(n)
    if (current == nullptr) {
        return;
    }
    result.push_back(current->data);
    preorder(current->left,result);
    preorder(current->right,result);
}
void MyBST::inorder(int num) {
    std::vector<std::pair<std::vector<std::string>,int>> result;
    inorder(this->root,result);
    int ip_count=0;
    for (int i = 0; i < num && ip_count<num; i++) {
        for (int j=0; j<result[i].first.size(); j++) {
            std::cout << result[i].first[j] << " " << result[i].second << std::endl;
            ip_count++;
        }
    }
}

void MyBST::inorder(MyNodeBST* current, std::vector<std::pair<std::vector<std::string>,int>>& result) {         //O(n)
    if (current == nullptr) {
        return;
    }
    inorder(current->right,result);
    result.push_back(std::make_pair(current->ip ,current->data));
    inorder(current->left,result);
}
void MyBST::postorder() {
    std::vector<int> result;
    postorder(this->root,result);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << ",";
    }
}

void MyBST::postorder(MyNodeBST* current, std::vector<int>& result) {   //O(n)
    if (current == nullptr) {
        return;
    }
    postorder(current->left,result);
    postorder(current->right,result);
    result.push_back(current->data);
}

void MyBST::level() {                                       //O(n)
    if (this->root == nullptr) {
        return;
    }
    std::queue<MyNodeBST*> q;
    q.push(this->root);
    while (!q.empty()) {
        MyNodeBST *current = q.front();
        q.pop();

        std::cout<< current->data << ",";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
/*
void MyBST::visit(int type) {
    if (type == 1) {
        preorder();
    }else if (type == 2) {
        inorder();
    }else if (type == 3) {
        postorder();
    }else if (type == 4) {
        level();
    }else {
        std::cout<< "Numero Invalido" << std::endl;
    }
}*/

int MyBST::height() {
    return height(this->root);
}

int MyBST::height(MyNodeBST* current) {     //O(n)
    if (current == nullptr) {
        return 0;
    }
    int left = height(current->left);
    int right = height(current->right);
    if (left>right) {
        return left + 1;
    }else {
        return right + 1;
    }
}

void MyBST::ancestors(int data) {       //O(h)
    MyNodeBST *current = this->root;
    while (current != nullptr) {
        if (current->data == data) {
            return;
        }
        std::cout << current->data << ",";
        if (current->data > data) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
}

int MyBST::whatLevelAmI(int data) {         //O(h)
    MyNodeBST *current = this->root;
    int level = 0;
    while (current != nullptr) {
        if (current->data == data) {
            return level;
        }
        if (current->data > data) {
            current = current->left;
        }else {
            current = current->right;
        }
        level++;
    }
    return -1;
}