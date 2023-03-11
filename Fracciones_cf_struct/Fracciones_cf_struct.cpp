    #include <iostream> 
#include <conio.h> 

using namespace std;

struct f {
    int dem1, dem2, num1, num2;
} fraccion;

int operacion(int mcd, int dem1, int dem2, int num1, int num2, int p1, int p2, int top, int entero, int a, int b, int i) {
    if (entero >= 1) {
        cout << "El resultado es: " << entero << " ";
    }
    if (top == 0) {
        cout << " El resultado es 0";
    }
    if (entero > 0) {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << a << "/" << b << "\n";
    }
    else {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << "El resultado es: " << a << "/" << b << "\n";
    }
    return a, b;
}

int main() {
    int op, num1{}, dem1, num2{}, dem2, mcd{}, p1{}, p2{}, top, entero, s = 0, i{}, a{}, b{};

    cout << "Introduce la primera fraccion:\n";
    cout << "Numerador: ";
    cin >> fraccion.num1;
    cout << "Denominador: ";
    cin >> fraccion.dem1;
    cout << "Introduce la segunda fraccion:\n";
    cout << "Numerador: ";
    cin >> fraccion.num2;
    cout << "Denominador: ";
    cin >> fraccion.dem2;

    cout << fraccion.dem1;

    cout << "Elige una opicion:\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n";
    op = _getch();
    if (fraccion.dem1 == 0 || fraccion.dem2 == 0) {
        cout << "Introduce un valor correcto";
    }
    else {
        int top;
        switch (op) {
        case '1':
            mcd = fraccion.dem1 * fraccion.dem2;
            p1 = fraccion.num1 * fraccion.dem2;
            p2 = fraccion.num2 * fraccion.dem1;
            top = p1 + p2;
            entero = top / mcd;
            operacion(mcd, fraccion.dem1, fraccion.dem2, num1, num2, p1, p2, top, entero, a, b, i);
            break;

        case '2':
            mcd = fraccion.dem1 * fraccion.dem2;
            p1 = fraccion.num1 * fraccion.dem2;
            p2 = fraccion.num2 * fraccion.dem1;
            top = p1 - p2;
            entero = top / mcd;
            operacion(mcd, fraccion.dem1, fraccion.dem2, num1, num2, p1, p2, top, entero, a, b, i);
            break;

        case '3':
            mcd = fraccion.dem1 * fraccion.dem2;
            top = fraccion.num1 * fraccion.num2;
            entero = top / mcd;
            operacion(mcd, fraccion.dem1, fraccion.dem2, num1, num2, p1, p2, top, entero, a, b, i);
            break;

        case  '4':
            mcd = fraccion.num2 * fraccion.dem1;
            top = fraccion.num1 * fraccion.dem2;
            entero = top / mcd;
            operacion(mcd, fraccion.dem1, fraccion.dem2, num1, num2, p1, p2, top, entero, a, b, i);
            break;
        }
    }
    return 0;
}