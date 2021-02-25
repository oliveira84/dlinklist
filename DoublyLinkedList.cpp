// Inicio de DoublyLinkedList.cpp

#include "DoublyLinkedList.h"
#include <iostream>

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = tail = nullptr;
    size_of_list = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head != nullptr)
        pop_front();
}

template <class T>
void DoublyLinkedList<T>::add_first_node(T key)
{
    if (size_of_list == 0)
    {
        tail = head = alloc_node(key);
        ++size_of_list;
    }
}


template <class T>
Node<T>* DoublyLinkedList<T>::alloc_node(T key)
{
    Node<T>* new_node;
    try { new_node = new Node<T>(key); }
    catch (std::bad_alloc& erro)
    {
        std::cout << "Memory allocation error: " << erro.what() << std::endl;
        return nullptr;
    }
    return new_node;
}

template <class T>
void DoublyLinkedList<T>::push_back(T key)
{
    if (size_of_list >= 2)
    {
        Node<T>* new_node = alloc_node(key);
        new_node->prev = tail;
        tail->next = new_node;        
        tail =new_node;
        ++size_of_list;
    }
    else if (size_of_list == 1)
    {
        tail = alloc_node(key);
        tail->prev = head;
        head->next = tail;
        ++size_of_list;
    }
    else if (size_of_list == 0)
        add_first_node(key);
}

template <class T>
void DoublyLinkedList<T>::push_front(T key)
{
    if (size_of_list >= 2)
    {
        Node<T>* new_node = alloc_node(key);
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        ++size_of_list;
    }
    else if (size_of_list == 1)
    {
        head = alloc_node(key);
        head->next = tail;
        tail->prev = head;
        ++size_of_list;
    }

    else if (size_of_list == 0)
        add_first_node(key);
}

template <class T>
void DoublyLinkedList<T>::pop_back()
{
    if (size_of_list >= 2)
    {
        tail = tail->prev;
        delete (tail->next);
        tail->next = nullptr;
        --size_of_list;
    }
    else if (size_of_list == 1)
    {
        delete head;
        head = tail = nullptr;
        --size_of_list;
    }
}

template <class T>
void DoublyLinkedList<T>::pop_front()
{
    if (size_of_list >= 2)
    {
        head = head->next;
        delete (head->prev);
        head->prev = nullptr;
        --size_of_list;
    }
    else if (size_of_list == 1)
    {
        delete head;
        head = tail = nullptr;
        --size_of_list;
    }
}

template <class T>
Node<T>* DoublyLinkedList<T>::remove(Node<T>* node)
{
    if (node != nullptr) // checks if the list is empty
    {
        if (node->next == nullptr) // it's the tail
        {
            pop_back();
            return nullptr;
        }
        if (node->prev == nullptr) // it's the head
        {
            pop_front();
            return head;
        }

        Node<T>* next = node->next;
        Node<T>* prev = node->prev;
        prev->next = next;
        next->prev = prev;
        delete node;
        --size_of_list;
        return next;
    }
    return nullptr;
}

template <class T>
Node<T>* DoublyLinkedList<T>::find_key(T key, Node<T>* starting_position)
{
    Node<T>* iterator = starting_position;
    while (iterator != nullptr)
        if (iterator->key == key)
            return iterator;
    return nullptr;
}

template <class T>
bool DoublyLinkedList<T>::key_exists(T key)
{
    if (find_key(key))
        return true;
    return false;
}

template <class T>
void DoublyLinkedList<T>::remove_key_occurrences(T key)
{
    Node<T>* iterator = head;
    while (iterator != nullptr)    
        iterator = remove(key,iterator);    
}
