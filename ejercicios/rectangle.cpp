#include <iostream>

/*
Andrea Vianey Díaz Álvarez A01750147
Jorge Alberto Penagos Méndez A01378450
Emilio Campuzano Mejia A01378948
*/

using namespace std;

class Rectangle{

public:

    Rectangle (int width, int height)
    {
        _width = width;
        _height = height;
    }

    int get_width()
    {
        return _width;
    }

    int get_height()
    {
        return _height;
    }

    int perimeter()
    {
        return ((2*_width )+(2*_height));
    }
    int area()
    {
       return (_height * _width);
    }

    void draw()
    {
        for (int i = 0;  i < _height; ++i)
        {
            for (int j = 0;  j < _width; ++j)
            {
                cout << "* ";

            }
        cout << endl;
        }
    }
private:

    int _width;
    int _height;

};

int main()
{
    Rectangle a {4, 3};
    Rectangle b {5, 10};

    cout << "Primer rectángulo" << endl;
    cout << "Ancho: " << a.get_width() << endl;
    cout << "Altura: " << a.get_height() << endl;
    cout << "Perímetro: " << a.perimeter() << endl;
    cout << "Área: " << a.area() << endl << endl;
    a.draw();

    cout << endl << "Segundo rectángulo" << endl;
    cout << "Ancho: " << b.get_width() << endl;
    cout << "Altura: " << b.get_height() << endl;
    cout << "Perímetro: " << b.perimeter() << endl;
    cout << "Área: " << b.area() << endl << endl;
    b.draw();

    return 0;
}