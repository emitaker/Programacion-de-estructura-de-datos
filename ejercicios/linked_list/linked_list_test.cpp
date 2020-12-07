/*
Práctica #9: LinkedList

Emilio Campuzano Mejia A01378948
Eva Denisse Vargas Sosa A01377098
Omar Rodrigo Sorchini Puente A01749389

*/
#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
//              Lista de números enteros
    cout << "Lista de números" << endl;
    cout << endl;
    LinkedList<int> int_list;
    cout << "size: "<<int_list.size() << endl;
    cout << "is_empty: "<<int_list.is_empty() << endl;

    int_list.insert_front(1);
    int_list.insert_front(2);
    int_list.insert_front(3);
    int_list.insert_back(4);
    int_list.insert_back(5);
    int_list.insert_back(6); // 3 2 1 4 5 6

    cout << int_list << endl;
    cout << "is_empty: "<< int_list.is_empty() << endl;
    cout << "get: " << int_list.get(2) << endl;

    int_list.remove_front();
    cout << "remove front: "<< int_list << endl;
    int_list.remove_back();
    cout << "remove back: "<< int_list << endl;

//              Lista de palabras
    cout << endl;
    cout << "Cambio a lista str" << endl;
    cout << endl;

//      Lista de palabras número 1
    LinkedList<string> str_list {"gorila" , "chimpance", "mandril"};
    cout << "size: "<< str_list.size() << endl;

    cout << str_list << endl;
    cout << "is_empty: " << str_list.is_empty() << endl;
    cout << "contains: "<< str_list.contains("mandril") << endl;
    cout << "get: " << str_list.get(2) << endl;

    str_list.remove_front();
    cout << "remove front: " <<str_list << endl;
    str_list.remove_back();
    cout << "remove back: " <<str_list << endl;

//      Lista de palabras número 2
    LinkedList<string> str_list_2{"tucan", "perico", "pajaro carpintero"};
    str_list.extend(str_list_2);
    cout << "Lista extendida: " << str_list << endl;
    cout << endl;

    while(!str_list_2.is_empty()){
        str_list_2.remove_front();
        cout << str_list_2 << endl;
        if(str_list_2.is_empty()){
            break;
        }
    }
    cout << str_list_2 << endl;


    return 0;
}