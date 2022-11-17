#pragma once

#include <cmath>
#include <iostream>

template<class F> double biseccion(F f)
{
	double a, b, e, r=0.0;
	std::cout << "Ingrese el valor de a: ";
	std::cin >> a;
	std::cout << "Ingrese el valor de b: ";
	std::cin >> b;
	std::cout << "Ingrese el valor del error: ";
	std::cin >> e;
	
	if(f(a)*f(b) < 0) {
		do {
			r = (a+b)/2.0;
			std::cout << "Aproximando... " << r << "\n";
		
			if( f(a)*f(r) < 0  )
				b = r;
			else
				a = r;
		}
		while( std::abs(f(r)) > e );
	}

	else 
		std::cout << "No se cumple la condicion inicial!\n";	

	return r;
}


