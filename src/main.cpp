#include "algoritmos/biseccion.hpp"
#include "algoritmos/newton_raphson.hpp"
#include "algoritmos/integrales.hpp"
#include "algoritmos/riemman.hpp"
#include "algoritmos/euler.hpp"
#include <iostream>
#include <cmath>

constexpr const double PI = 3.14159265359;

constexpr double f(double x, double y)
{
	return x+(y/5);
}

constexpr double g(double x) 
{
	return std::sin(x);
}

using namespace mcc;

int main()
{
	std::cout << "Utilizando Euler\n";
	auto resultado = ecuacion_diferencial<Euler>(f, {0, -3}, 0.2, 6);
	for(auto& p : resultado)
		std::cout << "x: " << p.first << "\ty: " << p.second << "\n";

	std::cout << "Utilizando Euler\n";
	resultado = ecuacion_diferencial<EulerMejorado>(f, {0, -3}, 0.2, 6);
	for(auto& p : resultado)
		std::cout << "x: " << p.first << "\ty: " << p.second << "\n";

	return 0;
}
