#include "algoritmos/biseccion.hpp"
#include "algoritmos/newton_raphson.hpp"
#include "algoritmos/integrales.hpp"
#include "algoritmos/riemman.hpp"
#include <iostream>
#include <cmath>

constexpr const double PI = 3.14159265359;

constexpr double f(double x, double y)
{
	return (x*x)+(y*y);
}

constexpr double g(double x) 
{
	return std::sin(x);
}

using namespace mcc;

int main()
{
	double resultado;

	std::cout << "Utilizando Trapecio 1 variable...\n";
	resultado = integrar<Trapecio>(g, 0, PI/2, 4);
	std::cout << "Resultado: " << resultado << "\n";

	std::cout << "Utilizando Simpson 2 variables...\n";
	resultado = integrar<Simpson>(f, 0, 2, 2, 0, 2, 2);
	std::cout << "Resultado: " << resultado << "\n";

	return 0;
}
