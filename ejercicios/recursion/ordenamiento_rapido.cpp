#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class SortableArray {

public:
    SortableArray(vector<T>& vec): _vec(vec) { }

    void quicksort()
    {

    }

private:
    vector<T>& _vec;
};

int main() {
    vector<int> a {6, 1, 2, 5, 9};
    SortableArray<int> sa(a);
    sa.quicksort();

    return 0;
}