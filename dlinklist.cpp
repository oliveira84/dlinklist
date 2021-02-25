#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp" // Para poder colocar os metodos "template" no ficheiro cpp

int main()
{
    std::cin.get();
    DoublyLinkedList<int> dl;
    for (int i = 0; i < 20000; ++i)
    {
        dl.push_back(i);
        dl.push_front(i - 20000);
    }
    std::cout << "Hello World!\n";
}
