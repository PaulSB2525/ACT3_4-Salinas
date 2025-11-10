//
// Created by Guest on 25/09/2025.
//

#ifndef CLASE2509_MYLINKEDLIST_H
#define CLASE2509_MYLINKEDLIST_H
#include <ostream>

struct MyNodoLL {
    std::pair<long long,std::string> data;
    MyNodoLL* next;
    MyNodoLL* prev;

    MyNodoLL(std::pair<long long,std::string> data, MyNodoLL* next, MyNodoLL* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    MyNodoLL(std::pair<long long,std::string> data) : MyNodoLL(data, nullptr, nullptr) {}
};

class MyLinkedList {

public:
    int size;
    MyNodoLL* head;
    MyNodoLL* tail;

    MyLinkedList();
    ~MyLinkedList();
    void flush();
    int length();
    bool isEmpty();
    std::pair<long long,std::string> first();
    std::pair<long long,std::string> last();
    std::pair<long long,std::string> getAt(int pos);
    void setAt(int pos, std::pair<long long,std::string> data);
    void insertFirst(std::pair<long long,std::string> data);
    void insertLast(std::pair<long long,std::string> data);
    void insertAt(int pos, std::pair<long long,std::string> data);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend std::ostream& operator<<(std::ostream& os,const MyLinkedList& ll);

};


#endif //CLASE2509_MYLINKEDLIST_H