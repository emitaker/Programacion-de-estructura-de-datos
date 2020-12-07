/*
Emilio Campuzano Mejia A01378948
Eva Denisse Vargas Sosa A01377098
Omar Rodrigo Sorchini Puente A01749389
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


struct Pais{
    string nombre;
    int oro;
    int plata;
    int bronce;
};




bool compa(const Pais& a, const Pais& b)
{
    if (a.oro > b.oro){
        return true;
    }else if (a.oro == b.oro && a.plata > b.plata){
        return true;
    }else if (a.plata == b.plata && a.bronce > b.bronce){
        return true;
    }else if (a.bronce == b.bronce && a.nombre < b.nombre){
        return true;
    }
}

int main(int argc, const char* argv[])
{
    if(argc != 2){
        cerr << "Favor de indicar el nombre del archivo de entrada." << endl;
        exit(1);
    }

    string nombre_archivo = argv[1];
    ifstream entrada(nombre_archivo);
    if (entrada.fail()){
        cerr << "Error al intentar abrir archivo." << endl;
        exit(1);
    }

    string linea;
    vector<Pais> info;
    while (getline(entrada, linea)){
        istringstream iss(linea);
        Pais p;
        iss >> p.nombre;
        iss >> p.oro;
        iss >> p.plata;
        iss >> p.bronce;
        info.push_back(p);
    }

    entrada.close();

    sort(info.begin(), info.end(), compa);

    for (Pais p: info){
        cout << p.nombre << " "
            << p.oro << " "
            << p.plata << " "
            << p.bronce << endl;
    }


    return 0;
}