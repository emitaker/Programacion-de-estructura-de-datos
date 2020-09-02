//Omar Rodrigo Sorchini Puente A01749389
//Eva Denisse Vargas Sosa A01377098
//Emilio Campuzano Mejía A01378948

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int binary_search(vector<T> vec, T value){

int lower_bound = 0;
int upper_bound = vec.size() - 1;

 while (lower_bound <= upper_bound){
        int midpoint = (upper_bound + lower_bound)/2;
        T value_at_midpoint = vec[midpoint];
        if (value < value_at_midpoint){
            upper_bound = midpoint - 1;
        }
        else if (value > value_at_midpoint){
            lower_bound = midpoint + 1;
        }
        else if(value == value_at_midpoint){
            return midpoint;
        }

}
return -1;
}

template<typename T>
vector<T> bubble_sort(vector<T> vec){

    int unsorted_until_index = vec.size() - 1;
    bool sorted = false;
    while (!sorted){
        sorted = true;
        for (int i = 0;i < unsorted_until_index;++i){
            if (vec[i] > vec[i+1]){
                sorted = false;
                T temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;


            }

        }
    --unsorted_until_index;
    }
return vec;
}

template<typename T>
int print_vec(vector<T> vec){
    for (int i = 0;i<vec.size();++i){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

int main()
{//list = [65, 55, 45, 35, 25, 15, 10]
//bubble_sort(list)
//print
    vector <int> a {5,7,-9,1,2,10,-5,8,1,0,2,13,20,-99};
    vector <double> b {3.1,13.0,42.5};
    vector<string> c {"enero", "febrero", "marzo", "abril", "mayo", "junio"};


    a = bubble_sort(a);
    int x = binary_search(a,2);
    cout << a[6] << endl;
    cout << "El 2 esta en el índice " << x <<endl;

    b = bubble_sort(b);
    int y = binary_search<double>(b,42.5);
    cout << b[2] << endl;
    cout << "El 42.5 esta en el índice " << y <<endl;

    c = bubble_sort(c);
    string mes = "enero";
    int z = binary_search(c,mes);
    cout << c[1] << endl;
    cout << "El enero esta en el índice " << z <<endl;

    return 0;
}