#include <iostream>

using namespace std;

struct Nodo {
    char   data;
    Nodo*  next;
};


// Time complexity: O(N)
void imprime_lista(Nodo* inicio)
{
    while (inicio != nullptr) {
        cout << inicio->data << " ";
        inicio = inicio->next;
    }
    cout << endl;
}

//  Time complexity: O(N)
void imprime_reversa_lista(Nodo* inicio)
{
    if (inicio != nullptr) {
        imprime_reversa_lista(inicio->next);
        cout << inicio->data << " ";
    }
}

// Time complexity: O(N)
int longitud(Nodo* inicio)
{
    if (inicio == nullptr) {
        return 0;
    } else {
        return 1 + longitud(inicio->next);
    }
}

/*
// Time complexity: O(1)
void inserta_inicio(Nodo*& inicio, char data)
{
    Nodo* nuevo = new Nodo;
    nuevo->data = data;
    nuevo->next = inicio;
    inicio = nuevo;
}
*/

// Time complexity: O(N)
void libera_lista(Nodo* inicio)
{
    while (inicio != nullptr) {
        Nodo* borrar = inicio;
        inicio = inicio->next;
        delete borrar;
        borrar = nullptr;
    }
}

bool existe(Nodo* inicio, char x)
{
    while (inicio != nullptr) {
        if (inicio->data == x) {
            return true;
        }
        inicio = inicio->next;
    }
    return false;
}

void duplica(Nodo* inicio)
{
    while (inicio != nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->data = inicio->data;
        nuevo->next = inicio->next;
        inicio->next = nuevo;
        inicio = inicio->next->next;
    }
}

bool borra(Nodo*& inicio, char data)
{
    // Lista vacía, nada que borrar
    if (inicio == nullptr) {
        return false;
    }

    // ¿Hay que borrar el primero nodo?
    if (inicio->data == data) {
        Nodo* anterior = inicio;
        inicio = inicio->next;
        delete anterior;
        anterior = nullptr;
        return true;
    }

    // Para otros elementos
    Nodo* anterior = inicio;
    Nodo* actual = inicio->next;
    while (actual != nullptr) {
        if (actual->data == data) {
            anterior->next = actual->next;
            delete actual;
            actual = nullptr;
            return true;
        }
        anterior = actual;
        actual = actual->next;
    }
    return false;
}

void inserta_orden(Nodo*& inicio, char data)
{
    Nodo* nuevo = new Nodo;
    nuevo->data = data;
    nuevo->next = nullptr;

    if (inicio == nullptr){
        inicio == nuevo;
    } else if(data <= inicio->data){
        nuevo->next = inicio;
        inicio = nuevo;
    } else{
        Nodo* anterior = inicio;
        Nodo* actual = inicio->next;

        while(actual != nullptr && data > actual->data){
            anterior = actual;
            actual = actual->next;
        }

        anterior->next = nuevo;
        nuevo->next = actual;
    }
}

int main()
{
    Nodo* lst = nullptr;

    inserta_orden(lst, 'X');
    inserta_orden(lst, 'C');
    inserta_orden(lst, 'B');
    inserta_orden(lst, 'W');
    inserta_orden(lst, 'A');
    inserta_orden(lst, 'T');


    cout << longitud(lst) << endl;
    imprime_lista(lst);

    cout << boolalpha;
    cout << existe(lst, 'A') << endl;
    cout << existe(lst, 'W') << endl;

    duplica(lst);
    imprime_lista(lst);

    cout << borra(lst, 'X') << endl;
    imprime_lista(lst);

    cout << borra(lst, 'B') << endl;
    imprime_lista(lst);

    cout << borra(lst, 'W') << endl;
    imprime_lista(lst);

    cout << borra(lst, 'C') << endl;
    imprime_lista(lst);

    cout << borra(lst, 'C') << endl;
    imprime_lista(lst);

    cout << borra(lst, 'X') << endl;
    imprime_lista(lst);

    libera_lista(lst);
    lst = nullptr;

    return 0;
}