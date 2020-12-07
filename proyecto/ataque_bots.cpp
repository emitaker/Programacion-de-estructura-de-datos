/*

Proyecto: El ataque los bots

    Profesor: Ariel Ortiz
    Materia: Estructura de Datos TC1031
    Grupo: 603

    Alumnos y número de equipo: 1
        Eva Denisse Vargas Sosa A01377098
        Omar Rodrigo Sorchini Puente A01749389
        Emilio Campuzano Mejía A01378948

Preguntas a responder:
    1. ¿Cuáles son las cinco direcciones IP
        (sin el importar el número de puerto) que tuvieron más
        accesos ilegales?

    2. ¿Con qué frecuencia aparecen cada uno de los distintos mensajes de
        error (razón de la falla)?

    3. ¿Cuántos números de puertos distintos fueron atacados en total?

    4. ¿En qué semana se detectaron una mayor cantidad de accesos
        ilegales? Se puede suponer que: 1) una semana inicia el día lunes
        y termina el domingo, y 2) las fechas de los archivos de bitácoras
        corresponden al año 2020.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <string.h>

using namespace std;


//We define this structure to read each value separately of the Binnacle
struct Binnacle{
        string month;
        string day;
        string hour;
        string ip;
        string port;
        string fail;
    };



//This function help us to identify each part of the Binnacle
multiset<string> information(vector<Binnacle> info, string value)
{
    multiset<string> info_spe;
    for (auto b : info){
        if (value == "month"){
            info_spe.insert(b.month);
        }else if (value == "day"){
            info_spe.insert(b.day);
        }else if (value == "hour"){
            info_spe.insert(b.hour);
        } else if (value == "ip"){
            info_spe.insert(b.ip);
        } else if (value == "port"){
            info_spe.insert(b.port);
        }   else if (value == "fail"){
            info_spe.insert(b.fail);
        } else {
            cout << "That value doesn't exist" << endl;
        }
    }
    return info_spe;
}

//The "top5" function answer the 1st question.
// Time complexity: O(N)
void top5(multiset<string> top)
{
    multiset<pair<int,string>> order;
    multiset<string,int>::iterator itd;
    pair<int,string> pairs;
    string repeat = "";
    for (itd = top.begin(); itd != top.end(); itd++){
        pairs = make_pair(top.count(*itd),*itd);
        if (repeat == ""){ // check if it is the first time
            repeat = *itd;
            order.insert (pairs);
        }
        if (repeat != *itd){
            order.insert (pairs);
        }
        repeat = *itd;
    }
    cout << "Top 5 repeated values: " << endl;
    int i=0;
    multiset<pair<int,string>>::reverse_iterator itd2;
    for (itd2=order.rbegin();itd2!=order.rend();itd2++){//This prints only the top 5 repeated values
        cout << (itd2->first) << " -> " << (itd2->second) << endl;
        ++i;
        if (i == 5){
            break;
        }
    }
    cout << endl;
}

// The function "frequency answer the 2nd question
//TIme complexity: O(N)
void frequency(const multiset<string> fq){

    multiset<pair<string,int>> cores;
    auto fact = fq.begin();
    auto range = fq.equal_range(*fact);
    pair<string,int> pairs;
    while(fact != fq.cend()){
        auto elem1 = *fact;
        auto elem2 = fq.count(*fact);
        fact = range.second;

        pairs = make_pair(elem1, elem2);
        cores.insert(pairs);

        if (fact == fq.cend()){
            break;
        }
        else{
            range = fq.equal_range(*fact);
        }
    }

    cout << "The frequency of each error is: " << endl;
    for (auto i: cores){
        cout << i.first << endl;
        cout << i.second << endl;
    }
    cout << endl;
}

//The function "sum" answer the 3rd question
//Time complexity: O(N)
void sum(const multiset<string> fq){
    multiset<pair<string,int>> cores;
    multiset<string,int>::iterator itd;
    pair<string,int> pairs;
    string repeat = "";
    for (itd = fq.begin(); itd != fq.end(); itd++){
        pairs = make_pair(*itd, fq.count(*itd));
        if (repeat == ""){// check if it is the first time
            repeat = *itd;
            cores.insert (pairs);
        }if (repeat != *itd){
            cores.insert (pairs);
        }
        repeat = *itd;
    }
    multiset<pair<string,int>>::iterator itd2;
    cout << "Total attacked ports: " << endl;
    cout << cores.size() << endl;
    cout << endl;
}

// The function "week_attacked" answer the question number 4:
//Time complexity: O(N)
void week_attacked(const multiset<string> fq){
    multiset<pair<int,string>> order;
    multiset<string,int>::iterator itd;
    pair<int,string> pairs;
    string repeat = "";
    for (itd = fq.begin(); itd != fq.end(); itd++){
        pairs = make_pair(fq.count(*itd),*itd);
        if (repeat == ""){// check if it is the first time
            repeat = *itd;
            order.insert (pairs);
        }
        if (repeat != *itd){
            order.insert (pairs);
        }
        repeat = *itd;
    }

    cout << "The week more attacked: " << endl;
    int i=0;
    multiset<pair<int,string>>::reverse_iterator itd2;

    for (itd2=order.rbegin();itd2!=order.rend();itd2++){
        cout << (itd2->first) << " -> " << (itd2->second) << endl;
        ++i;
        if (i == 1){
            break;
        }
    }
    cout << endl;
}


int main (int argc, const char* argv[]){
    //The main function receives a parameter in order to read a file

    if(argc != 2){
        cerr << "Favor de indicar el nombre del archivo de entrada." << endl;
        exit(1);
    }
    string file_name = argv[1];
    ifstream arch(file_name);
    if (arch.fail()){
        cerr << "Error al intentar abrir archivo." << endl;
        exit(1);
    }

    struct tm date;
    char size_week [100];
    memset(&date,0,sizeof(size_week));

    map <string, int> months{
        {"Jan", 1},{"Feb", 2},{"Mar", 3},{"Apr", 4},{"May", 5},
        {"Jun", 6},{"Jul", 7},{"Ago", 8},{"Sep", 9},{"Oct", 10},
        {"Nov", 11},{"Dec", 12}
    };

    multiset<string> no_weeks;
    string line;
    vector<Binnacle> info;
    while (getline(arch, line)){

        istringstream iss(line);
        string direction;
        int find_char;
        int len_port;
        int len_fail;
        int find_beg_fail;

        Binnacle b;
        iss >> b.month;
        iss >> b.day;
        iss >> b.hour;
        iss >> direction;
        find_char = direction.find(":");
        len_port = direction.length()-find_char;
        b.ip = direction.substr(0,find_char);
        b.port = direction.substr(find_char+1,len_port);
        find_beg_fail = line.find_last_of(":")+len_port;
        len_fail = line.length()-find_beg_fail;
        b.fail = line.substr(find_beg_fail+1, len_fail);
        info.push_back(b);

        date.tm_mday = stoi(b.day);
        date.tm_mon = months[b.month];
        date.tm_year = 120;
        mktime(&date);
        strftime(size_week, sizeof(size_week), "%W", &date);
        no_weeks.insert(size_week);
    }
    arch.close();

    multiset<pair<string,int>> fq;
    // Answer to first question
    multiset<string> lis1 = information(info, "ip");
    top5(lis1);
    // Answer to second question
    multiset<string> lis2 = information(info, "fail");
    frequency(lis2);
    // Answer to third question
    multiset<string> lis3 = information(info, "port");
    sum(lis3);
    // Answer to fourth question
    week_attacked(no_weeks);
}
