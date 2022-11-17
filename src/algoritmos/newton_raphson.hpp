#pragma once

#include <iostream>
#include <cmath>

template<class Function> double newton_raphson(Function f, Function dxf)
{
    double x0, x1, e;
    std::cout << "Ingrese x0: ";
    std::cin >> x0;
    x1 = x0;

    std::cout << "Ingrese el valor de E: ";
    std::cin >> e;

    while(std::abs(f(x1)) > e)
    {
        std::cout << "x0: " << x0 << "\n";
        std::cout << "f(x0): " << f(x0) << "\n";
        std::cout << "dxf(x0): " << dxf(x0) << "\n";
        
        x1 = x0 - f(x0)/dxf(x0);

        std::cout << "x1: " << x1 << "\n";
        x0 = x1;
    }
    std::cout << "Raiz aproximada: " << x1 << "\n";

    return x0;
}