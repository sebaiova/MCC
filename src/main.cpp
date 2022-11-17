#include "algoritmos/biseccion.hpp"
#include "algoritmos/newton_raphson.hpp"
#include "algoritmos/integrales.hpp"
#include "algoritmos/riemman.hpp"
#include "algoritmos/euler.hpp"
#include <iostream>
#include <cmath>

constexpr const double PI = 3.14159265359;

constexpr double f(double, double y)
{
	return (y*y) + 1;
}

constexpr double g(double x) 
{
	return std::sin(x);
}

using namespace mcc;

int main()
{
	std::cout << "Utilizando Euler\n";
	auto resultado = euler(f, std::make_pair(0, 0), 0.1, 6);
	for(auto& p : resultado)
		std::cout << p.first << "\ty: " << p.second << "\n";

	return 0;
}
