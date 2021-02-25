#pragma once
#include "Node.h"
#include "Node.cpp"

template<class T>
class DoublyLinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int size_of_list;
    void add_first_node(T key);
    Node<T>* find_key(T key, Node<T>* starting_position);
    Node<T>* remove(Node<T>* node);
public:
    DoublyLinkedList();
   ~DoublyLinkedList();

    Node<T>* alloc_node(T key);
    void push_back(T key);
    void push_front(T key);
    void pop_back();
    void pop_front();
    bool key_exists(T key);
    void remove_key_occurrences(T key);
};



