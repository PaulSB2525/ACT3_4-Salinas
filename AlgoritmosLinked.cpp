//
// Created by paul_ on 08/10/2025.
//
#include <iostream>
#include "AlgoritmosLinked.h"

AlgoritmosLinked::AlgoritmosLinked(){};
// Usamos un pointer-to-pointer para pasar como referencia
// a los apuntadores de los nodos
// Recuperado de: https://www.geeksforgeeks.org/cpp/cpp-pointer-to-pointer-double-pointer
void AlgoritmosLinked::dividirLista(MyNodoLL* head, MyNodoLL** frente, MyNodoLL** atras) {
    MyNodoLL* rapido;
    MyNodoLL* lento;
    lento = head;
    rapido = head->next;

    while (rapido != nullptr) {
        rapido = rapido->next;
        if (rapido != nullptr) {
            lento = lento->next;
            rapido = rapido->next;
        }
    }

    *frente = head;
    *atras = lento->next;
    lento->next = nullptr;
    // O(n)
}

MyNodoLL* AlgoritmosLinked::merge(MyNodoLL* izquierda, MyNodoLL* derecha) {
    if (!izquierda) return derecha;
    if (!derecha) return izquierda;

    MyNodoLL* resultado = nullptr;

    if (izquierda->data.first <= derecha->data.first) {
        resultado = izquierda;
        resultado->next = merge(izquierda->next, derecha);
    } else {
        resultado = derecha;
        resultado->next = merge(izquierda, derecha->next);
    }

    return resultado; // O(n)
}

MyNodoLL* AlgoritmosLinked::mergeSortNodos(MyNodoLL* head) {

    if (head == nullptr || head->next == nullptr){
        return head;
    }

    MyNodoLL* frente;
    MyNodoLL* atras;

    dividirLista(head, &frente, &atras);

    frente = mergeSortNodos(frente);
    atras = mergeSortNodos(atras);

    return merge(frente, atras);
    // O(n log n)
}

void AlgoritmosLinked::ordenaMerge(MyLinkedList& lista) {
    lista.head = mergeSortNodos(lista.head);

    // Recalcular el tail
    MyNodoLL* actual = lista.head;
    lista.tail = nullptr;
    while (actual != nullptr) {
        if (actual->next == nullptr) {
            lista.tail = actual;
        }
        actual = actual->next;
    }
    // O(n)
}

MyNodoLL* AlgoritmosLinked::busquedaSecuencial(MyLinkedList& lista, long long key) {
    MyNodoLL* actual = lista.head;
    int lenght = lista.length();
    int pos = 0;

    for (int i = 0; i < lenght; i++) {
        if (actual->data.first >= key) {
            return actual;
        }
        actual = actual->next;
    }
    return nullptr;
}

bool MyBST::insert(int data, int ip) {      //O(h)
    if (this->root == nullptr) {
        this->root = new MyNodeBST(data, ip);
        this->size++;
        return true;
    }
    MyNodeBST *current = this->root;
    MyNodeBST *aux = nullptr;
    while (current != nullptr) {

        aux = current;
        if (current->ip == ip) {

        }
        /*
        aux = current;
        if (current->data == data) {
            return false;
        }
        if (current->data > data) {
            current = current->left;
        }else {
            current = current->right;
        }
        */
    }
    if (aux->data > data) {
        aux->left = new MyNodeBST(data, ip);
    }else {
        aux->right = new MyNodeBST(data, ip);
    }
    this->size++;
    return true;
}