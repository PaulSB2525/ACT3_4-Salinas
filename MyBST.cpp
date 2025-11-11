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

MyBST::MyBST() { // O(1) solo asigna los valores iniciales
    this->root = nullptr;
    this->size = 0;
}

MyBST::~MyBST() { // O(n) recorre todo el arbol 1 vez
    destroyNode(this->root);
}

void MyBST::destroyNode(MyNodeBST* current){  // O(n) recorre todo el arbol 1 vez
    if (current== nullptr) {
        return;
    }
    destroyNode(current->left);
    destroyNode(current->right);

    delete current;
}

int MyBST::length() { // O(1) solo devuelve el tamaño
    return this->size;
}

bool MyBST::isEmpty() { // O(1) solo compara el tamaño
    return this->size==0;
}

bool MyBST::search(int data, MyNodeBST *current) {             //en el mejor de los casos O(1), en el peor O(h) 
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

bool MyBST::search(int data) {        // O(h) busca un valor en el arbol
    return search(data, this->root);
}

bool MyBST::remove(int data) {              //O(h) elimina un nodo del arbol
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

bool MyBST::insert(int data, std::string ip) {      //O(h) inserta un nodo en el arbol
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

void MyBST::preorder() {      //O(n) recorre todo el arbol 1 vez
    std::vector<int> result;
    preorder(this->root,result);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << ",";
    }
}

void MyBST::preorder(MyNodeBST* current, std::vector<int>& result) {        //O(n) recorre todo el arbol 1 vez
    if (current == nullptr) {
        return;
    }
    result.push_back(current->data);
    preorder(current->left,result);
    preorder(current->right,result);
}

//Este metodo se uso al reves (reverse inorder)
void MyBST::inorder(int num) {       //O(n) recorre todo el arbol 1 vez
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

void MyBST::inorder(MyNodeBST* current, std::vector<std::pair<std::vector<std::string>,int>>& result) {         //O(n) recorre todo el arbol 1 vez
    if (current == nullptr) {
        return;
    }
    inorder(current->right,result);
    result.push_back(std::make_pair(current->ip ,current->data));
    inorder(current->left,result);
}

void MyBST::postorder() {      //O(n) recorre todo el arbol 1 vez
    std::vector<int> result;
    postorder(this->root,result);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << ",";
    }
}

void MyBST::postorder(MyNodeBST* current, std::vector<int>& result) {   //O(n) recorre todo el arbol 1 vez
    if (current == nullptr) {
        return;
    }
    postorder(current->left,result);
    postorder(current->right,result);
    result.push_back(current->data);
}

void MyBST::level() {                                       //O(n) recorre todo el arbol 1 vez
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

int MyBST::height() {        //O(n) calcula la altura del arbol
    return height(this->root);
}

int MyBST::height(MyNodeBST* current) {     //O(n) calcula la altura del arbol
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

void MyBST::ancestors(int data) {       //O(h) muestra los ancestros de un nodo
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

int MyBST::whatLevelAmI(int data) {         //O(h) devuelve el nivel de un nodo
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