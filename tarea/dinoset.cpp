#include <iostream>

using namespace std;

const int total_dinos = 8;

enum class DinoId {
    velocirraptor,      // 0
    estegosaurio,       // 1
    tiranosaurio,       // 2
    procompsagnatus,    // 3
    triceratops,        // 4
    paquicefalosaurio,  // 5
    parasaurolofus,     // 6
    pteranodon          // 7
};

class


int main()
{
    cout << boolalpha;

    DinoSet a;
    a.add(DinoId::velocirraptor);
    a.add(DinoId::tiranosaurio);
    cout << "a = " << a << endl;

    DinoSet b;
    b.add(DinoId::tiranosaurio);
    b.add(DinoId::procompsagnatus);
    cout << "b = " << b << endl;

    cout << "a contains velociraptor: "
        << a.contains(DinoId::velocirraptor) << endl;
    cout << "a contains procompsagnatus: "
        << a.contains(DinoId::procompsagnatus) << endl;

    DinoSet c = a + b;
    cout << c << endl;
    cout << "size of c: " << c.size() << endl;

    DinoSet d = a * b;
    cout << "d = " << d << endl;

    cout << "d is_empty: " << d.is_empty() << endl;
    d.remove(DinoId::tiranosaurio);
    cout << "d = " << d << endl;
    cout << "d is_empty: " << d.is_empty() << endl;
    cout << "size of d: " << d.size() << endl;

    DinoSet e = a - b;
    cout << "e = " << e << endl;

    DinoSet f = !a;
    cout << "f = "<< f << endl;

    cout << "a == b: " << (a == b) << endl;

    DinoSet g;
    g.add(DinoId::velocirraptor);
    cout << "g = " << g << endl;
    cout << "e == g: " << (e == g) << endl;

    return 0;
}