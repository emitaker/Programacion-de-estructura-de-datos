/*
*Archivo de encabezado para el TDA (tipo de dato abstracto)
*que representa una pila LIFO (last-in first-out).
*/

#pragma once

#include <iostream>
#include <sstream>

using namespace std;

const int max_stack = 10;


template <typename T>
class Stack{

    public:

        //Time complexity: O(1)
        void push(T obj)
        {
            if (_level == max_stack){
                throw overflow_error("Stack overflow.");
            }
            _info[_level] = obj;
            ++_level;
        }

        // Time complexity O(1)
        T pop()
        {
            if(is_empty()){
                throw underflow_error("Stack underflow.");
            }
            --_level;
            return _info[_level];
        }

        //Time complexity O(1)
        T peek() const
        {
            if (is_empty()){
                throw underflow_error("Stack underflow.");
            }
            return _info[_level - 1];
        }

        //Time complexity O(1)
        int size()const
        {
            return _level;
        }

        //Time complexity O(1)
        bool is_empty() const
        {
            return size()==0;
        }

        void clear()
        {
            _level = 0;
        }

        string to_string() const
        {
            ostringstream oss;

            oss << "Top -> {";
            bool first = true;


            for (int i = _level -1; i >= 0; --i){
                if (first){
                    first = false;
                }else{
                    oss << ", ";
                }
                oss << _info[i];
            }

            oss << "}";
            return oss.str();
        }

    private:
        T _info[max_stack] {};
        int _level {};

};

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack)
{
    return os << stack.to_string();
}