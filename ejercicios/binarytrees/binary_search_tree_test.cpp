#include <iostream>
#include <vector>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    // BinarySearchTree<char> t1;

    // t1.insert('F');
    // t1.insert('L');
    // t1.insert('D');

    // BinarySearchTree<int> t2 {5, 7, 3, 1, 4, 10, 9, 8, 6};

    // cout << t1.size() << endl;
    // cout << t2.size() << endl;

    // vector<char> v1;
    // vector<int> v2;

    // t1.in_order(v1);
    // t2.in_order(v2);

    // for (char c: v1) {
    //     cout << c << " ";
    // }
    // cout << endl;

    // for (int i: v2) {
    //     cout << i << " ";
    // }
    // cout << endl;

    BinarySearchTree<int> t1;
    cout << "is empty" << t1.is_empty() << endl;
    cout << t1.height() << endl;
    t1.insert(5);
    cout << t1.height() << endl;
    t1.insert(3);
    t1.insert(10);
    cout << t1.height() << endl;
    t1.insert(7);
    t1.insert(8);
    cout << t1.height() << endl;
    t1.insert(4);
    t1.insert(1);
    t1.insert(15);
    t1.insert(6);
    t1.insert(20);
    cout << t1.height() << endl;
    BinarySearchTree<int> t2;
    cout << "is empty" << t1.is_empty() << endl;
    cout << "is empty" << t2.is_empty() << endl;
    cout << "contains "<< t1.contains(15)<< endl;
    cout << "contains "<< t2.contains(5)<< endl;
    return 0;
}