#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "AlgoritmosLinked.h"
#include "MyLinkedList.h"

//Paul Aureliano Sarmiento Baldenebro A00227824
//Victor André Velázquez Salcido A01647326
//Nestor Efrain Caceres Claros A01646134
//Jose Alfredo Vergara A01645391

// En AlgoritmosLinked.cpp usamos un pointer-to-pointer
// para pasar como referencia los apuntadores de los nodos
// Recuperado de: https://www.geeksforgeeks.org/cpp/cpp-pointer-to-pointer-double-pointer
// Video guia tutorial playlist https://www.youtube.com/playlist?list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh


int main() {

    std::ifstream archivoEntrada("bitacora2.txt");
    if (!archivoEntrada) {
        std::cout << "No se encuentra el archivo\n";
        return 1;
    }

    MyLinkedList registrosPonderados;

    std::string linea;

    while (std::getline(archivoEntrada, linea)) {
        std::istringstream flujoIp(linea);
        std::string ipStr, valoresAnteriores;
        flujoIp >> valoresAnteriores >> valoresAnteriores >> valoresAnteriores >> ipStr;
        std::istringstream flujoIp2(ipStr);
        std::string primStr, seguStr, tercStr, cuarStr, quinStr;
        std::getline(flujoIp2, primStr, '.');
        std::getline(flujoIp2, seguStr, '.');
        std::getline(flujoIp2, tercStr, '.');
        std::getline(flujoIp2, cuarStr, ':');
        std::getline(flujoIp2, quinStr);

        long long prim = std::stoi(primStr);
        long long segu = std::stoi(seguStr);
        long long terc = std::stoi(tercStr);
        long long cuar = std::stoi(cuarStr);
        long long quin = std::stoi(quinStr);
        long long ipPonderada = prim * 1000000000000000
                     + segu * 1000000000000
                     + terc * 1000000000
                     + cuar * 10000
                     + quin;
        registrosPonderados.insertLast({ipPonderada, linea});
    }

    AlgoritmosLinked algoritmos1;

    algoritmos1.ordenaMerge(registrosPonderados);

    std::ofstream archivoOrdenado("bitacoraOrdenadaIP-Eq2-BST.txt");

    MyNodoLL* registro = registrosPonderados.head;
    while(registro != nullptr){
        archivoOrdenado << registro->data.second << "\n";
        registro = registro->next;
    }
    archivoOrdenado.close();

    std::vector<std::string> ips;

    std::ifstream archivoLectura("bitacoraOrdenadaIP-Eq2-BST.txt");


    while (std::getline(archivoLectura, linea)) {
        std::istringstream flujoIp(linea);
        std::string ipStr, valoresAnteriores;
        flujoIp >> valoresAnteriores >> valoresAnteriores >> valoresAnteriores >> ipStr;
        int pos = ipStr.find(':');
        ipStr = ipStr.substr(0, pos);
        ips.push_back(ipStr);
    }

    archivoOrdenado.close();



    int elements=5;                       // <-- CAMBIAR LA CANTIDAD DE IPs AQUI!!
    algoritmos1.makeTree(ips, elements);

    std::cout<<"Programa finalizado con exito"<<std::endl;

    return 0;
}
