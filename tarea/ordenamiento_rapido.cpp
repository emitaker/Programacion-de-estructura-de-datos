#include <iostream>
#include <vector>


using namespace std;

template<typename T>
class SortableArray {

public:
    SortableArray(vector<T>& vec): _vec(vec) {}


    int partition(int left_pointer, int right_pointer)
    {   int pivot_position;
        T pivot;

        pivot_position = right_pointer;
        pivot = _vec[pivot_position];

        right_pointer -= 1;

        while (true) {
            while (_vec[left_pointer] < pivot){
                left_pointer += 1;
            }
            while (_vec[right_pointer] > pivot){
                right_pointer -= 1;
            }
            if (left_pointer >= right_pointer){
                break;
                }else{
                    swap(left_pointer, right_pointer);
                }
        }
        swap(left_pointer, pivot_position);
        return left_pointer;
    }

    void swap(int pointer_1,int pointer_2){
        T temp_value;

        temp_value = _vec[pointer_1];
        _vec[pointer_1] = _vec[pointer_2];
        _vec[pointer_2] = temp_value;

    }

    void quicksort(int left_index,int right_index){
        int pivot_position;

        if (right_index - left_index <= 0){
            return;
        }
        pivot_position = partition(left_index, right_index);

        quicksort(left_index, pivot_position - 1);

        quicksort(pivot_position + 1, right_index);

    }

private:
    vector<T>& _vec;
};

template<typename T>
int print_vec(vector<T> vec){
    for (int i = 0;i<vec.size();++i){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    /*vector<int> a {6,1,2,5,9};
    SortableArray<int> sa(a);
    sa.quicksort();*/
    vector<int> a = {0, 5, 2, 1, 6, 3};
    vector<double> b = {0.45, 5.789, 2.631, 1.1112, 6.98746631, 3.33369};
    vector<string> c = {"ola", "como", "estas", "gatito", "araña", "miel"};

    SortableArray<int> sa(a);
    sa.quicksort(0, 5);

    SortableArray<double> sb(b);
    sb.quicksort(0, 5);

    SortableArray<string> sc(c);
    sc.quicksort(0, 5);

    print_vec(a);
    print_vec(b);
    print_vec(c);


}