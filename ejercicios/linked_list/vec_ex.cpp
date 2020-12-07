#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> char_vec{'A','B','C','D'};

    // for (char a: char_vec) {
    //     cout << a << endl;
    // }

    for (auto iterador = char_vec.begin(); iterador != char_vec.end(); ++iterador){
        char dato = *iterador;
        cout << dato << endl;
    }

    return 0;
}