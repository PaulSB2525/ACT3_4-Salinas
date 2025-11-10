//
// Created by paul_ on 08/10/2025.
//

#ifndef ALGORITMOSLINKED_H
#define ALGORITMOSLINKED_H

#include "MyLinkedList.h"
#include "MyBST.h"


class AlgoritmosLinked {

    MyLinkedList lista;

    void dividirLista(MyNodoLL* head, MyNodoLL** frente, MyNodoLL** atras);
    MyNodoLL* merge(MyNodoLL* izquierda, MyNodoLL* derecha);
    MyNodoLL* mergeSortNodos(MyNodoLL* head);

public:
    AlgoritmosLinked();
    void ordenaMerge(MyLinkedList &lista);
    MyNodoLL* busquedaSecuencial(MyLinkedList &lista, long long key);


};



#endif //ALGORITMOSLINKED_H