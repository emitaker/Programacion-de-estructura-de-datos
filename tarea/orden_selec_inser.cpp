//Emilio Campuzano Mejía A01378948
//Eva Denisse Vargas A01377098
// Omar Rodrigo Sorchini Puente A01749389

#include <iostream>
#include <vector>

using namespace std;

//Time complexity:O(N^2)
template<typename T>
void selection_sort(vector<T>& vec){
    for(int i = 0; i < vec.size(); i++) {
    int lowestNumberIndex = i;
        for(int j = i + 1; j < vec.size(); j++) {
            if(vec[j] < vec[lowestNumberIndex]) {
                lowestNumberIndex = j;
            }
        }
        if(lowestNumberIndex != i) {
            T temp = vec[i];
            vec[i] = vec[lowestNumberIndex];
            vec[lowestNumberIndex] = temp;
        }
    }
}

//Time complexity:O(N^2)
template<typename T>
void insertion_sort(vector<T>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        int lowestNumberIndex = i;
        for(int j = i + 1; j < vec.size(); j++) {
            if(vec[j] < vec[lowestNumberIndex]) {
                lowestNumberIndex = j;
            }
        }
        if(lowestNumberIndex != i) {
            T temp = vec[i];
            vec[i] = vec[lowestNumberIndex];
            vec[lowestNumberIndex] = temp;
        }
    }
}

//Time complexity:O(N)
template<typename T>
int print_vec(vector<T> vec){
    for (int i = 0;i<vec.size();++i){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

//Time complexity:O(1)
int main()
{
    vector<int> nums1 {5,7,8,1,3,6,11};
    vector<int> nums2 {45,87,95,101,66};
    vector<string> str1 {"omar", "emilio","mishi", "eva","hitler" };
    vector<string> str2 {"yui", "papaya", "kamara", "guayaba"};
    vector<double> dou1 {3.14167894, 2.73415189, 7777777.77777, 6666666.6666};
    vector<double> dou2 {117.45123, 123456789.987654321, 54684.111, 89746.322};

    cout << "Ordenamiento de numeros enteros" << endl;
    selection_sort (nums1);
    print_vec(nums1);
    insertion_sort(nums2);
    print_vec(nums2);

    cout << endl;
    cout << "Ordenamiento de strings" << endl;
    selection_sort (str1);
    print_vec(str1);
    insertion_sort(str2);
    print_vec(str2);

    cout << endl;
    cout << "Ordenamiento de numeros con punto decimal" << endl;
    selection_sort (dou1);
    print_vec(dou1);
    insertion_sort(dou2);
    print_vec(dou2);

    return 0;
}