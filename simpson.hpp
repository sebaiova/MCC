#include <cmath>
#include <iostream>

template<class Function> double simpson(Function f)
{
    double a, b, n, h, r;
    bool par = false;

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
        r += ( f(i) * (par ? 2 : 4 ));
        par = !par;
    }
    
    return r*(h/3);
}