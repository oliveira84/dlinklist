#pragma once

template<class T>
struct Node
{
    Node* prev;
    Node* next;
    T key;
    Node(T key);    
    ~Node();   
};



