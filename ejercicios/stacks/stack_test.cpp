#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    cout << stack1 << endl;
    cout << stack1.pop() << " ";
    cout << stack1.pop() << " ";
    stack1.push(4);
    cout << stack1.peek() << " ";
    cout << stack1.pop() << " ";
    cout << stack1.pop() << endl;
    cout << stack1.is_empty() << endl;
    try {
        stack1.pop();
    } catch (underflow_error e) {
        cout << "Algo pasó.\n";
    }

    Stack<string> stack2;

    stack2.push("a");
    stack2.push("b");
    stack2.push("c");
    cout << stack2 << endl;
    cout << stack2.size() << endl;
    cout << stack2.peek() << endl;
    stack2.clear();
    cout << stack2 << endl;
    cout << stack2.size() << endl;
}