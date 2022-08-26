#include <cmath>
#include <iostream>

template<class Function> double trapecios(Function f)
{
    double a, b, n, h, r;

    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;

    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;

    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    h = (b-a)/n;

    r = f(a) + f(b);
    for(double i=a+h; i<b; i+=h)
    {
        r += f(i)*2;
    }

    return r*(h/2);
}