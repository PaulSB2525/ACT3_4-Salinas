//
// Created by paul_ on 08/10/2025.
//
#include <iostream>
#include "AlgoritmosLinked.h"

AlgoritmosLinked::AlgoritmosLinked(){};
// Usamos un pointer-to-pointer para pasar como referencia
// a los apuntadores de los nodos
// Recuperado de: https://www.geeksforgeeks.org/cpp/cpp-pointer-to-pointer-double-pointer
void AlgoritmosLinked::dividirLista(MyNodoLL* head, MyNodoLL** frente, MyNodoLL** atras) { // O(n) divide la lista en 2 mitades
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

    return resultado; // O(n) mezcla dos listas ordenadas
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
    // O(n log n) mezcla y ordena la lista
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
    // O(n) recalcula el tail de la lista
}

void AlgoritmosLinked::makeTree(std::vector<std::string>& v, int elements) {
    MyBST ardo;
    int ip_count=1;
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i] == v[i+1]) {
            ip_count++;
        }else {
            ardo.insert(ip_count,v[i]);
            ip_count = 1;
        }
    }
    ardo.insert(ip_count,v[v.size()-1]);
    ardo.inorder(elements);
    // O(n log n) inserta los elementos en el arbol y los muestra ordenados
}