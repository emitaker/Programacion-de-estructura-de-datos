#include <iostream>

using namespace std;


// Time complexity: O(N)
int fact(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

// Time complexity: O(2^N)
void hanoi(int n, char origen, char destino, char temp)
{
    if (n > 0) {
        hanoi(n - 1, origen, temp, destino);
        cout << "Mover disco " << n << " de " << origen << " a "
            << destino << endl;
        hanoi(n - 1, temp, destino, origen);
    }
}

int main()
{
    /*for (int i = 0; i < 20; ++i) {
        cout << i << "! = " << fact(i) << endl;
    }*/
    hanoi(3, 'A', 'C', 'B');
    return 0;
}