#include "algoritmos/biseccion.hpp"
#include "algoritmos/newton_raphson.hpp"
#include "algoritmos/trapecios.hpp"
#include "algoritmos/simpson.hpp"
#include "algoritmos/riemman.hpp"
#include <iostream>
#include <cmath>

double PI = 3.14159265359;

double f(double x, double y)
{
	return 16-(std::pow(x,2))-(2*(std::pow(y,2)));
}

int main()
{
	std::cout << "Utilizando Riemman...\n";
	double resultado = riemman(f, 0, 0, 2, 2, 4, 4);
	std::cout << "Resultado: " << resultado << "\n";
	return 0;
}
