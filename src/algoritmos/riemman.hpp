#pragma once

template <class Function>
double riemman(Function f, double x0, double y0, double x1, double y1, int n, int m)
{
    double dx { (x1-x0)/n };
    double dy { (y1-y0)/m };
    double area { dx * dy };
    double volumen { 0 };

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            volumen += (f(x0+(dx*i), y0+(dy*j)))*area;

    return volumen;
}