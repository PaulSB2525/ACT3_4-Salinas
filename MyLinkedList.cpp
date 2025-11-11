//
// Created by Guest on 25/09/2025.
//

//ref: https://www.youtube.com/watch?v=qk67wS7WYxo&list=WL&index=1

#include "MyLinkedList.h"
#include <iostream>

MyLinkedList::MyLinkedList() {          //O(1) Solo asigna los puntero
    this->size = 0;
    this->head=this->tail=nullptr;
}

void MyLinkedList::flush() {       //O(n) Recorre toda la lista 1 vez
    if (this->size != 0) {
        MyNodoLL* actual = this->head;
        for (int i=0;i<this->size; i++) {
            MyNodoLL* temp = actual->next;
            delete actual;
            actual = temp;
        }
        this->head=this->tail=nullptr;
        this->size=0;
    }
}

MyLinkedList::~MyLinkedList() {         //O(n) Recorre toda la lista 1 vez
    flush();
}


int MyLinkedList::length() {    //O(1) Solo devuelve 1 variable
    return this->size;
}
bool MyLinkedList::isEmpty() {      //O(1) Hace solo una comparacion
    return this->size == 0;
}
std::pair<long long,std::string> MyLinkedList::first() {         //O(1) Accede directamente a la variable
    if(this->size!=0) {
        return this->head->data;
    }else {
        throw std::invalid_argument("No se puede obtener el primer elemento de una lista enlazada");
    }
}
std::pair<long long,std::string> MyLinkedList::last() {          //O(1) Accede directamente a la variable
    if(this->size!=0) {
        return this->tail->data;
    }else {
        throw std::invalid_argument("No se puede obtener el ultimo elemento de una lista enlazada");
    }
}

std::pair<long long,std::string> MyLinkedList::getAt(int pos) {      //O(n) Recorre toda la lista 1 vez
    MyNodoLL* actual = this->head;
    for (int i=0; i<this->size; i++) {
        if (i==pos) {
            return actual->data;
        }
        actual = actual->next;
    }
    throw std::invalid_argument("No se encontro");
}

void MyLinkedList::setAt(int pos, std::pair<long long,std::string> data) { 
    if (this->size>pos) {
        MyNodoLL* actual = this->head;
        for (int i=0; i<this->size; i++) {
            if (i==pos) {
                actual->data = data;
                break;
            }
            actual = actual->next;          //O(n) Recorre toda la lista 1 vez
        }
    }else {
        throw std::invalid_argument("No se encontro");
    }
}

void MyLinkedList::insertFirst(std::pair<long long,std::string> data) {
    MyNodoLL* nuevo=new MyNodoLL(data,this->head,nullptr);
    this->head=nuevo;
    this->size++;
    if (this->size==1) {            //O(1) Accede directamente a la variable
        this->tail=nuevo;
    }
}

void MyLinkedList::insertLast(std::pair<long long,std::string> data) {
    MyNodoLL* nuevo=new MyNodoLL(data,nullptr, this->tail);
    if (this->size==0) {
        this->head=this->tail=nuevo;
    }else {
        this->tail->next=nuevo;             //O(1) Accede directamente a la variable
        this->tail=nuevo;
    }
    this->size++;
}

void MyLinkedList::insertAt(int pos, std::pair<long long,std::string> data) {
    if (pos == 0) {
        MyNodoLL* nuevo=new MyNodoLL(data,this->head, nullptr);
        this->head=nuevo;
        this->size++;
        if (this->size==1) {        //O(n) Recorre toda la lista 1 vez
            this->tail=nuevo;
        }
    }
    else if (this->size>=pos) {
        MyNodoLL* actual = this->head;
        for (int i=0; i<pos-1; i++) {
            actual = actual->next;
        }
        MyNodoLL* nuevo=new MyNodoLL(data,actual->next,actual->prev);
        actual->next=nuevo;
        if (pos == this->size) {
            this->tail=nuevo;
        }

        this->size++;

    }else {
        throw std::invalid_argument("No se encontro");
    }
}

void MyLinkedList::removeFirst() {      //O(1) Accede directamente a la variable
    if (this->size!=0) {
        MyNodoLL* actual = this->head;
        this->head=actual->next;
        delete actual;
        this->size--;
    }else {
        throw std::invalid_argument("No se puede eliminar el primer elemento de una lista enlazada vacia");
    }
}

void MyLinkedList::removeLast() {       //O(n) Recorre toda la lista 1 vez
    MyNodoLL* actual = this->head;
    if (this->size==1) {
        this->head=actual->next;
        delete actual;
        this->size--;
    }else if (this->size!=0) {
        for (int i=0; i<this->size-2; i++) {
            actual=actual->next;
        }
        this->tail=actual;
        delete actual->next;
        actual->next=nullptr;
        this->size--;
    }else {
        throw std::invalid_argument("No se puede eliminar el ultimo elemento de una lista enlazada vacia");
    }
}

void MyLinkedList::removeAt(int pos) {      //O(n) Recorre toda la lista 1 vez

    MyNodoLL* actual = this->head;
    if (pos==0) {
        this->head=actual->next;
        delete actual;
        this->size--;
    }else if (this->size>pos) {
        for (int i=0; i<pos-1; i++) {
            actual=actual->next;
        }
        MyNodoLL* aux = actual->next;
        actual->next=aux->next;
        if (pos==this->size-1) {
            this->tail=actual;
        }
        delete aux;
        this->size--;
    }
    else {
        throw std::invalid_argument("No se encontro");
    }
}

std::ostream& operator<<(std::ostream& os,const MyLinkedList& ll) {
    MyNodoLL* actual = ll.head;
    for (int i=0; i<ll.size; i++) {         //O(n) Recorre toda la lista 1 vez
        os<<actual->data.first;
        os<<",";
        actual=actual->next;
    }
    return os;
}