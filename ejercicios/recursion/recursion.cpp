#include <iostream>

using namespace std;

int fact(int n)
{
    if(n == 0){
        return 1;
    }else{
        return n * fact(n- 1);
    }
}

void hanoi(int n, char origen, char destino, char temp)
{
    if (n == 1){
        cout << "Mover disco " << n << " de " << origen << " a "
        << destino << endl;
    } else{
        hanoi(n - 1, origen, temp, destino);
        cout << "Mover disco " << n << " de " << origen << " a "
            << destino << endl;
        hanoi(n - 1, temp, destino, origen);
    }
}

int main()
{
    /*
    for(int i = 0; i < 20; ++i){
        cout << i << "! = " << fact(i) << endl;
    }
    */

    hanoi(5,'A', 'C', 'B');
    return 0;
}
