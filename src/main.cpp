#include "algoritmos/biseccion.hpp"
#include "algoritmos/newton_raphson.hpp"
#include "algoritmos/trapecios.hpp"
#include "algoritmos/simpson.hpp"
#include <iostream>
#include <cmath>

double f(double x)
{
	return std::tan(x);
}

/*double f(double x)
{
	return std::pow(x, 3) - 2*x -1;
}

double dxf(double x)
{
	return std::pow(3*x, 2) - 2;
}*/

int main()
{
	std::cout << "Utilizando Simpson...\n";
	double resultado = simpson(f);
	std::cout << "Resultado: " << resultado << "\n";
	return 0;
}
