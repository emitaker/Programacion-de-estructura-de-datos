#include <iostream>
#include <vector>

//Algorithm with n complexity
using namespace std;

template<typename T>
int linear_search(vector<T> vec, T value)
{
    for(int i=0; i < vec.size(); ++i){
        if(vec[i] == value){
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> a {5, 7, -9, 2, 10, -5, 8, 1, 0, 2, 13, -99} ;
    vector<double> b {3.1, 13.0, 45.8} ;
    vector<string> c {"lol","hola","no","se","que","pasa"};
    int x = linear_search(a, 2);
    cout << "El 2 esta en el indice " << x << endl;
    x = linear_search(b, 13.0);
    cout << "El 13 esta en el indice "<< x << endl;
    string mes = "no";
    x = linear_search(c, mes);
    cout << "\"no\" esta en el indice "<< x << endl;

    return 0;
}