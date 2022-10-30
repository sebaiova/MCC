#include "algoritmos/biseccion.hpp"
#include "algoritmos/newton_raphson.hpp"
#include "algoritmos/trapecios.hpp"
#include "algoritmos/simpson.hpp"
#include "algoritmos/riemman.hpp"
#include <iostream>
#include <cmath>

constexpr const double PI = 3.14159265359;

constexpr double f(double x, double y)
{
	return 16-(x*x)-(2*y*y);
}

int main()
{
	std::cout << "Utilizando Riemman...\n";
	double resultado = riemman(f, 0, 0, 2, 2, 8, 8);
	std::cout << "Resultado: " << resultado << "\n";
	return 0;
}
