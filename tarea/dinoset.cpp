//A01378948 Emilio Campuzano Mejia
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

string dino_names[] = {
    "velocirraptor",      // 0
    "estegosaurio",       // 1
    "tiranosaurio",       // 2
    "procompsagnatus",    // 3
    "triceratops",        // 4
    "paquicefalosaurio",  // 5
    "parasaurolofus",     // 6
    "pteranodon"
};

class DinoSet{

public:

    bool contains(DinoId id) const
    {
        int indice = static_cast<int>(id);
        return _dino[indice];
    }

    void add(DinoId id)
    {
        int indice = static_cast<int>(id);
        _dino[indice] = true;
    }

    void remove(DinoId id)
    {
        int indice = static_cast<int>(id);
        _dino[indice] = false;
    }

    bool is_empty() const
    {
        if (size() == 0){
            return true;
        }
    }

    int size() const
    {
        int counter = 0;
        for (int i = 0; i < total_dinos; ++i){
            DinoId id = static_cast<DinoId>(i);
            if (contains(id)){
                counter+=1;
            }
        }
        return counter;
    }

    DinoSet operator+(const DinoSet& other) const
    {
        DinoSet result;

        for (int i = 0; i < total_dinos; ++i){
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) || other.contains(id)){
                result.add(id);
            }
        }
        return result;
    }

    DinoSet operator*(const DinoSet& other) const
    {
        DinoSet result;

        for (int i = 0; i < total_dinos; ++i){
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) && other.contains(id)){
                result.add(id);
            }
        }
        return result;
    }

    DinoSet operator-(const DinoSet& other) const
    {
        DinoSet result;

        for (int i = 0; i < total_dinos; ++i){
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) && !other.contains(id)){
                result.add(id);
            }
        }
        return result;
    }

    DinoSet operator!() const
    {
        DinoSet result;

        for (int i = 0; i < total_dinos; ++i){
            DinoId id = static_cast<DinoId>(i);
            if (contains(id)){
                result.remove(id);
            }else{
                result.add(id);
            }
        }
        return result;

    }

    bool operator==(const DinoSet& other) const
    {
        for (int i = 0; i < total_dinos; ++i){
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) == other.contains(id)){
                return true;
            }
            else{
                return false;
            }
        }
    }

    string to_string() const
    {
        string result = "{";
        bool first = true;
        for (int i = 0; i < total_dinos; ++i){
            if (_dino[i]) {
                if (first){
                    first = false;
                }else{
                    result +=", ";
                }
                result += dino_names[i];
            }
        }
        return result + "}";
    }

private:
    bool _dino[total_dinos]{};
};

ostream& operator<<(ostream& os, const DinoSet& dino)
{
    return os << dino.to_string();
}

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
